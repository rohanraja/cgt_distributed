#include "execution.h"
#include <cstdio>
#include <queue>
#include <set>
#include <vector>
#include "util/ThreadPool.h"
#include "unistd.h"

using namespace std ;

namespace cgt {

using std::vector;
using std::atomic;
using std::mutex;

// ================================================================
// Sequential interpreter
// ================================================================

class SequentialInterpreter : public Interpreter {
public:
    SequentialInterpreter(ExecutionGraph* eg, const vector<MemLocation>& output_locs) 
    : eg_(eg), output_locs_(output_locs), storage_(eg->n_locs()), args_(NULL) { }

    cgtObject * get(const MemLocation& m) {
        return storage_[m.index()].get();
    }
    void set(const MemLocation& m, cgtObject * val) {
        storage_[m.index()] = val;
    }
    cgtObject * getarg(int argind) {
        cgt_assert(argind < args_->len);        
        return args_->members[argind].get();
    }
    cgtTuple * run(cgtTuple * newargs) {
        args_ = newargs;
        cgt_assert(newargs != NULL);
        cgt_assert(newargs->len == eg_->n_args());
        int icnt = 1 ;
        cout << "\nTotal Instructions = " << eg_->instrs().size() << endl ;
        for (Instruction* instr : eg_->instrs()) {
            cout << "\nFiring Instruction #" << icnt ; 
            icnt++;
            instr->fire(this);
        }
        cout << "\n\n";
        args_ = NULL;
        long n_outputs = output_locs_.size();
        cgtTuple * out = new cgtTuple(n_outputs);
        for (int i=0; i < n_outputs; ++i) {
            int index = output_locs_[i].index(); // XXX what is this used for?
            out->setitem(i, get(output_locs_[i]));
        }
        return out;
        // todo actually do something with outputs
    }
    ~SequentialInterpreter() {
    }

    void saveToFile(char *fname){
      
      printf("\nSaving Interpreter to file: %s\n", fname);

      ofstream f ;
      f.open(fname, ios::binary | ios::out);

      saveMemVector(output_locs_, f);
      eg_->save(f);

    }
private:
    ExecutionGraph* eg_;
    vector<MemLocation> output_locs_;
    vector<IRC<cgtObject>> storage_;
    cgtTuple * args_;
};


// ================================================================
// Parallel interpreter
// ================================================================

/**

In constructor, we build up a DAG on the instructions, where each instruction
points to the instructions that depend on it.
Also, each instruction knows its "in degree".
Thus, when all the predecessors of an instruction fire, we can enqueue that instruction.


*/

// #define DBG_PAR

class ParallelInterpreter: public Interpreter {
public:
    using InstrInd = long;    
    ParallelInterpreter(ExecutionGraph* eg, const vector<MemLocation>& output_locs, int num_threads);

    cgtObject * get(const MemLocation& m) {
        return storage_[m.index()].get();
    }
    void set(const MemLocation& m, cgtObject * val) {
        storage_[m.index()] = val;
    }
    cgtObject * getarg(int argind) {
        cgt_assert(argind < args_->len);
        return args_->members[argind].get();
    }

    cgtTuple * run(cgtTuple * newargs);
    void fire_instr(InstrInd instr_ind);
    void trigger_instr(InstrInd instr_ind);

    ~ParallelInterpreter() {
        // delete[] loc2mutex_; 
        delete[] instr2mutex_;
    }
private:
    ExecutionGraph* eg_;
    vector<MemLocation> output_locs_;
    vector<IRC<cgtObject>> storage_;
    cgtTuple * args_;
    ThreadPool pool_;

    vector<vector<InstrInd>> instr2next_; // instr -> instrs that depend on it
    vector<int> instr2indegree_; // instr -> number of instrs that it depends on
    vector<InstrInd> no_prereqs_; // instructions that can be fired initially
    vector<int> instr2insofar_;
    atomic<int> n_pending_; // number of pending instrs
    atomic<int> n_total_; // total instructions fired (just for debugging purposes)
    // mutex* loc2mutex_; // lock while writing to loc during execution. using c array because vector requires move constructor
    // xxx i think we can remove this
    mutex* instr2mutex_; // lock while checking if this instruction can fire or firing it
};

ParallelInterpreter::ParallelInterpreter(ExecutionGraph* eg, const vector<MemLocation>& output_locs, int num_threads)
  : eg_(eg), 
    output_locs_(output_locs), 
    storage_(eg->n_locs()), 
    args_(NULL),
    pool_(num_threads),
    instr2next_(eg->n_instrs()),
    instr2indegree_(eg->n_instrs()), 
    no_prereqs_(),
    instr2insofar_(eg->n_instrs()),
    n_pending_(0),
    n_total_(0),
    // loc2mutex_(new mutex[eg->n_locs()]),
    instr2mutex_(new mutex[eg->n_instrs()])
{
    vector<InstrInd> loc2lastwriter(eg->n_locs()); // for each location, last instruction to write to it
    InstrInd instr_ind=0; // will loop over instr index
    for (auto& instr : eg_->instrs()) {
        auto write_ind = instr->get_writeloc().index(); 
        // Instructions that have no read locations can be fired initially, except for ReturnByRef instructions
        if (instr->get_readlocs().empty() && instr->kind() != ReturnByRefKind) {
            no_prereqs_.push_back(instr_ind);
        }
        else {
            // All instructions depend on last writer to each read location
            for (auto& readmemloc : instr->get_readlocs()) {
                InstrInd lastwriter = loc2lastwriter[readmemloc.index()];
                instr2next_[lastwriter].push_back(instr_ind);                
                ++instr2indegree_[instr_ind];
            }
            // ReturnByRef instruction depends on last writer to write location
            if (instr->kind() == ReturnByRefKind) {
                InstrInd lastwriter = loc2lastwriter[write_ind];
                instr2next_[lastwriter].push_back(instr_ind);
                ++instr2indegree_[instr_ind];
            }
        }        
        loc2lastwriter[write_ind] = instr_ind;
        ++instr_ind;
    }

    #ifdef DBG_PAR
    for (int i=0; i < eg->n_instrs(); ++i) {
        printf("instrution %i triggers", i);
        for (InstrInd ii : instr2next_[i]) printf(" %i", ii);
        printf(", in degree = %i\n", instr2indegree_[i]);
    }
    #endif
}


cgtTuple * ParallelInterpreter::run(cgtTuple * newargs) {
    args_ = newargs;
    cgt_assert(newargs != NULL);
    cgt_assert(newargs->len == eg_->n_args());

    // setup
    n_pending_=0;
    n_total_=0;
    for (auto& n : instr2insofar_) { n = 0;}

    // trigger instructions that are ready initially
    for (InstrInd i : no_prereqs_) {
        trigger_instr(i);
    }

    // wait until everything's done
    while (n_pending_ > 0) {
        usleep(100);
    }

    args_ = NULL;
    long n_outputs = output_locs_.size();
    cgtTuple * out = new cgtTuple(n_outputs);
    for (int i=0; i < n_outputs; ++i) {
        int index = output_locs_[i].index();
        out->setitem(i, get(output_locs_[i]));
    }

    cgt_assert(n_total_ == eg_->n_instrs());

    return out;
}

void ParallelInterpreter::fire_instr(InstrInd instr_ind)
{
    Instruction* instr = eg_->instrs()[instr_ind];
    
    // XXX once we do in-place increments we'll have to start locking write location
    // for (auto& m : instr->get_readlocs()) instr2mutex_[m.index()].lock();
    // instr2mutex_[instr->get_writeloc().index()].lock();
    instr->fire(this);
    // for (auto& m : instr->get_readlocs()) instr2mutex_[m.index()].unlock();
    // instr2mutex_[instr->get_writeloc().index()].unlock();

    for (InstrInd& nextind : instr2next_[instr_ind]) {
        std::lock_guard<std::mutex> lock(instr2mutex_[nextind]);
        ++instr2insofar_[nextind];
        if (instr2insofar_[nextind] == instr2indegree_[nextind]) {
            trigger_instr(nextind);
        }
    }
    --n_pending_;    
    // if (!instr->quick()) printf("finished %i %s\n", instr_ind, instr->repr().c_str());


}

void ParallelInterpreter::trigger_instr(InstrInd instr_ind)
{
    ++n_pending_;
    ++n_total_;
    instr2insofar_[instr_ind] = 0;
    auto instr = eg_->instrs()[instr_ind];
    if (instr->quick()) {
        fire_instr(instr_ind);
    }
    else {
        // printf("triggered %i %s\n", instr_ind, instr->repr().c_str());
        pool_.enqueue(&ParallelInterpreter::fire_instr, this, instr_ind);        
    }
}


// ================================================================
// Instructions
// ================================================================

void LoadArgument::fire(Interpreter* interp) {
    interp->set(writeloc, interp->getarg(ind));
}

void Alloc::fire(Interpreter* interp) {
    int ndim = readlocs.size();
    vector<long> shape(ndim);
    for (int i=0; i < ndim; ++i) {
        cgtArray * sizeval = (cgtArray *)interp->get(readlocs[i]);
        cgt_assert(sizeval->dtype() == cgt_i8);
        shape[i] = sizeval->at<long>(0);
    }

    cgtArray* cur = static_cast<cgtArray*>(interp->get(writeloc));
    if (!(cur && cur->ndim() == ndim && std::equal(shape.begin(), shape.end(), cur->shape()))) {
        interp->set(writeloc, new cgtArray(ndim, shape.data(), dtype, writeloc.devtype()));
    }
}

void BuildTup::fire(Interpreter* interp) {
    cgtTuple * out = new cgtTuple(readlocs.size());
    for (int i=0; i < readlocs.size(); ++i) {
        out->setitem(i, interp->get(readlocs[i]));
    }
    interp->set(writeloc, out);
}

void ReturnByRef::fire(Interpreter* interp) {
    int n_inputs = readlocs.size();
    cgtObject * reads[n_inputs];
    for (int i=0; i < n_inputs; ++i) {
        reads[i] = interp->get(readlocs[i]);
    }
    cgtObject * write = interp->get(writeloc);
    callable(reads, write);
}

// TODO actually allocate tuple
void ReturnByVal::fire(Interpreter* interp) {
    int n_inputs = readlocs.size();
    vector<cgtObject *> args(n_inputs);
    for (int i = 0; i < n_inputs; ++i) {
        args[i] = interp->get(readlocs[i]);
    }    
    interp->set(writeloc, callable(args.data())); // XXX
}


// ================================================================
// Misc
// ================================================================

#include"dummyinter.h"
#include"helpers.h"

ExecutionGraph::~ExecutionGraph() {
    for (auto instr : instrs_) delete instr;
}

Interpreter* create_interpreter(ExecutionGraph* eg, vector<MemLocation> output_locs, int num_threads) {
    if (num_threads > 1) {
        return new ParallelInterpreter(eg, output_locs, num_threads);
    }
    else{
        return new SequentialInterpreter(eg, output_locs);
    }
}

Instruction * LoadArgument_load(ifstream &f){

  int ind;
  readf(f,ind);
  MemLocation wloc(f);

  return new LoadArgument("Load Argument", ind, wloc);
}

Instruction * Alloc_load(ifstream &f){

  cgtDtype dtype;
  readf(f,dtype);
  MemLocation wloc(f);
  vector<MemLocation> readlocs = loadMemVector(f);

  return new Alloc("Alloc", dtype, readlocs, wloc);
}

Instruction * BuildTup_load(ifstream &f){
  MemLocation wloc(f);
  vector<MemLocation> readlocs = loadMemVector(f);

  return new BuildTup("BuildTup", readlocs, wloc);
}

Instruction * Byref_load(ifstream &f){

  MemLocation wloc(f);
  vector<MemLocation> readlocs = loadMemVector(f);
  ByRefCallable callable(f) ;

  return new ReturnByRef("Return By Ref", readlocs, wloc, callable, false);

}

Instruction * Byval_load(ifstream &f){

  MemLocation wloc(f);
  vector<MemLocation> readlocs = loadMemVector(f);
  ByValCallable callable(f) ;

  return new ReturnByVal("Return By Val", readlocs, wloc, callable, false);

}

Interpreter* interpreter_from_file(char * fname){

  printf("\nLoading Interpreter from file: %s\n\n", fname);
  ifstream f;
  f.open(fname, ios::binary | ios::in);

  vector<MemLocation> outps = loadMemVector(f);
  ExecutionGraph *eg = loadExecutionGraph(f) ;

  Interpreter * inp = create_interpreter(eg,outps,0);

  printf("\nFINISHED LOADING INTERPRETER\n\n");
  return inp;
  return new DummyInterpreter(fname) ;

  // DummyInterpreter *inp = new DummyInterpreter(fname) ;
  // return inp ;
}


void interpreter_to_file(Interpreter * intp, const string &str) {

  intp->saveToFile((char*) str.c_str()) ;

}

void ExecutionGraph::save(ofstream &f) {

  writef(f, n_args_);
  writef(f, n_locs_);
  saveInstVector(instrs_, f);

}

void saveMemVector(vector<MemLocation> &mems, ofstream &f){

  int numInstrs = mems.size() ;

  writef(f, numInstrs);

  rep(i, numInstrs){

    mems[i].save(f) ;
  }


}

vector<MemLocation> loadMemVector(ifstream &f){

  int numOuts;

  readf(f, numOuts);

  vector<MemLocation> outps(numOuts) ;

  rep(i, numOuts){

    outps[i] = * new MemLocation(f);
  }

  return outps ;

}


void saveInstVector(vector<Instruction *> &mems, ofstream &f)
{
  long numInstrs = mems.size() ;

  writef(f, numInstrs);

  rep(i, numInstrs){

    mems[i]->save(f) ;
  }

}


vector<Instruction *> loadInstVector(ifstream &f){

  long num_instrs ;

  readf(f, num_instrs);
  trace(num_instrs);

  vector<Instruction *> instrs(num_instrs);

  int type ;

  rep(i,num_instrs){

    readf(f, type);
    trace(type);

    switch(type)
    {
      case 0:
        instrs[i] = LoadArgument_load(f);
        break;
      case 1:
        instrs[i] = Alloc_load(f);
        break;
      case 2:
        instrs[i] = BuildTup_load(f);
        break;
      case 3:
        instrs[i] = Byref_load(f);
        break;
      case 4:
        instrs[i] = Byval_load(f);
        break;

    };
    trace(instrs[i]->repr());

  }

  return instrs ;


}


ExecutionGraph * loadExecutionGraph(ifstream &f){

  long nargs, nlocs ;

  readf(f, nargs);
  readf(f, nlocs);

  trace(nargs);
  trace(nlocs);
  
  cout << "\n**** Loaded Instructions ****\n\n" ;
  vector<Instruction *> instrs = loadInstVector(f);
  cout << "\n**** Loaded Instructions ****\n" ;

  return new ExecutionGraph(instrs, nargs, nlocs) ;
}


typedef unsigned char byte ;

typedef int size_data;

void * loadCldata(ifstream &f){

  size_data structBytes ;
  readf(f, structBytes);
  trace(structBytes);

  if(structBytes == 0)
    return NULL ;

  byte* stdata = new byte[structBytes] ;

  readfs(f, stdata, structBytes);

  int numptrs;
  readf(f, numptrs);

  trace(numptrs);

  int sizeBlock;
  int st_offset;
  byte* block;

  byte* blockAddr;

  rep(i,numptrs){

    readf(f, sizeBlock);
    block = new byte[sizeBlock] ;
    readfs(f, block, sizeBlock);
    readf(f, st_offset);

    blockAddr = stdata + st_offset ;
    *((void **)(blockAddr)) = (void*) block ;

    trace(sizeBlock);
    trace(st_offset);

    int tst = * ( ((int*)block) + 1 ) ;
    trace(tst);

  }

  return (void*) stdata ;

}

void* loadByrefFunc(string & prefix){

  void * func ;

  string dllName = prefix + ".so" ;
  string funcName = "call_" + prefix ;
  string foldname = "/home/rohanraja/.cgt_cache/" ;
  dllName = foldname + dllName ;

  void *handle = dlopen(dllName.c_str(), RTLD_NOW | RTLD_GLOBAL);

  if(handle == NULL)
    cout << "CANNOT LOAD DLL!!\n";

  func = dlsym(handle, funcName.c_str());
  // func = (cgtByRefFun) dlsym(handle, "closure_a8e6eaa51a19a09311763a23e4857537");

   char * dlsym_error = dlerror();
    if (dlsym_error) {
        cerr << "Cannot load symbol destroy: " << dlsym_error << '\n';
    }
  return func;

}



}
