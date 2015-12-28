#pragma once
#include "cgt_common.h"
#include <vector>
#include <thread>
#include <string>
#include <fstream>
#include"helpers.h"

using namespace std ;
namespace cgt {
using std::vector;

// note: no-args initializers are only here because they're required by cython

class ByRefCallable {
public:
    cgtByRefFun fptr;
    void* data;
    ByRefCallable(cgtByRefFun fptr, void* data) : fptr(fptr), data(data) {}
    ByRefCallable() : fptr(NULL), data(NULL) {}
    void operator()(cgtObject ** reads, cgtObject * write) {
        (*fptr)(data, reads, write);
    }
};

struct ByValCallable {
public:
    cgtByValFun fptr;
    void* data;
    ByValCallable(cgtByValFun fptr, void* data) : fptr(fptr), data(data) {}
    ByValCallable() : fptr(NULL), data(NULL) {}
    cgtObject * operator()(cgtObject ** args) {
        return (*fptr)(data, args);
    }
};

class MemLocation {
public:
    MemLocation() : index_(0), devtype_(cgtCPU) {}
    MemLocation(long index, cgtDevtype devtype) : index_(index), devtype_(devtype) {}

    MemLocation(ifstream &f){

      long indx;
      int devtype;
      readf(f, indx);
      readf(f, devtype);
      index_ = indx ;
      devtype_ = cgtCPU ;
    }
    long index() const { return index_; }
    cgtDevtype devtype() const { return devtype_; }

    void save(ofstream &f){
      writef(f, index_);
      int devtype = 0;
      writef(f, devtype);

    }
private:
    long index_;
    cgtDevtype devtype_; // TODO: full device, not just devtype
};

class Interpreter;

enum InstructionKind {
    LoadArgumentKind,
    AllocKind,
    BuildTupKind,
    ReturnByRefKind,
    ReturnByValKind
};

class Instruction {
public:
    Instruction(InstructionKind kind, const std::string& repr, bool quick) : kind_(kind), repr_(repr), quick_(quick) { }
    virtual void fire(Interpreter*)=0;
    virtual ~Instruction() {};
    virtual const vector<MemLocation>& get_readlocs() const=0;
    virtual const MemLocation& get_writeloc() const=0;
    virtual void save(ofstream &f){}
    const std::string& repr() const { return repr_; }
    const InstructionKind kind() const {return kind_;}
    const bool quick() {return quick_;}
private:
    InstructionKind kind_;
    std::string repr_;
    bool quick_;
};

class ExecutionGraph {
public:
    ExecutionGraph(const vector<Instruction*>& instrs, long n_args, long n_locs)
    : instrs_(instrs), n_args_(n_args), n_locs_(n_locs) {}
    ~ExecutionGraph();
    const vector<Instruction*>& instrs() const {return instrs_;}
    long n_args() const {return n_args_;}
    long n_locs() const {return n_locs_;}
    long n_instrs() const {return instrs_.size();}
    void save(ofstream &f);
private:
    vector<Instruction*> instrs_; // owns, will delete
    long n_args_;
    long n_locs_;
};

class Interpreter {
public:
    // called by external code
    virtual cgtTuple * run(cgtTuple *)=0;
    // called by instructions:
    virtual cgtObject * get(const MemLocation&)=0;
    virtual void set(const MemLocation&, cgtObject *)=0;
    virtual cgtObject * getarg(int)=0;
    virtual ~Interpreter() {}
    virtual void saveToFile(char *){}
};

// pass by value because of cython
Interpreter* create_interpreter(ExecutionGraph*, vector<MemLocation> output_locs, int num_threads);


class LoadArgument : public Instruction  {
public:
    LoadArgument(const std::string& repr, int ind, const MemLocation& writeloc) : Instruction(LoadArgumentKind, repr, true), ind(ind), writeloc(writeloc) {}
    void fire(Interpreter*);
    const vector<MemLocation>& get_readlocs() const { return readlocs; }
    const MemLocation& get_writeloc() const { return writeloc; }
    void save(ofstream &f){
      int type = 0;
      writef(f, type);
      writef(f, ind);
      writeloc.save(f);
    }
private:
    int ind;
    vector<MemLocation> readlocs;  // empty
    MemLocation writeloc;
};

class Alloc : public Instruction {
public:
    Alloc(const std::string& repr, cgtDtype dtype, vector<MemLocation> readlocs, const MemLocation& writeloc)
    : Instruction(AllocKind, repr, true), dtype(dtype), readlocs(readlocs), writeloc(writeloc) {}
    void fire(Interpreter*);
    const vector<MemLocation>& get_readlocs() const { return readlocs; }
    const MemLocation& get_writeloc() const { return writeloc; }
    void save(ofstream &f){
      int type = 1;
      writef(f, type);
      writef(f, dtype);
      writeloc.save(f);
    }
private:
    cgtDtype dtype;
    vector<MemLocation> readlocs;
    MemLocation writeloc;
};

class BuildTup : public Instruction {
public:
    BuildTup(const std::string& repr, vector<MemLocation> readlocs, const MemLocation& writeloc)
    : Instruction(BuildTupKind, repr, true), readlocs(readlocs), writeloc(writeloc) {}
    void fire(Interpreter*);
    const vector<MemLocation>& get_readlocs() const { return readlocs; }
    const MemLocation& get_writeloc() const { return writeloc; }
private:
    vector<MemLocation> readlocs;
    MemLocation writeloc;
};

class ReturnByRef : public Instruction  {
public:
    ReturnByRef(const std::string& repr, vector<MemLocation> readlocs, const MemLocation& writeloc, ByRefCallable callable, bool quick)
    : Instruction(ReturnByRefKind, repr, quick), readlocs(readlocs), writeloc(writeloc), callable(callable) {}
    void fire(Interpreter*);
    const vector<MemLocation>& get_readlocs() const { return readlocs; }
    const MemLocation& get_writeloc() const { return writeloc; }
private:
    vector<MemLocation> readlocs;
    MemLocation writeloc;
    ByRefCallable callable;
};

class ReturnByVal : public Instruction  {
public:
    ReturnByVal(const std::string& repr, vector<MemLocation> readlocs, const MemLocation& writeloc, ByValCallable callable, bool quick)
    : Instruction(ReturnByValKind, repr, quick), readlocs(readlocs), writeloc(writeloc), callable(callable) {}
    void fire(Interpreter*);
    const vector<MemLocation>& get_readlocs() const { return readlocs; }
    const MemLocation& get_writeloc() const { return writeloc; }
private:
    vector<MemLocation> readlocs;
    MemLocation writeloc;
    ByValCallable callable;
};

Instruction * LoadArgument_load(ifstream &f);

void saveMemVector(vector<MemLocation> &mems, ofstream &f);
vector<MemLocation> loadMemVector(ifstream &f);

void saveInstVector(vector<Instruction *> &mems, ofstream &f);
vector<Instruction *>  loadInstVector(ifstream &f);

ExecutionGraph * loadExecutionGraph(ifstream &f);

// load interpreter from file
Interpreter* interpreter_from_file(char *) ;

// save interpreter to file
void interpreter_to_file(Interpreter *, const string &) ;

}
