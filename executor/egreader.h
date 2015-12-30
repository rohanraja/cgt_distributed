#include"execution.h"
#include"helpers.h"

using namespace cgt ;


Interpreter * interpreter_from_file2(char *);

long * get_0_int(cgtTuple *) ;


class DummyInterpreter : public Interpreter{

  char * fname ;

    ExecutionGraph* eg_; 
    vector<MemLocation> output_locs_;
    vector<IRC<cgtObject>> storage_;
    cgtTuple * args_;
  public:
    DummyInterpreter(char *nme){
      fname = nme ;
      printf("\nInitialized Dummy Interpreter\n");

    }
    cgtTuple * run(cgtTuple * newargs) {

      printf("\nRunning Function from file %s !!\n", fname);

      cgtTuple *inptup = new cgtTuple(1);
      
      static long shape[1] = {1};

      static cgtArray *arg0 = new cgtArray(1, shape, cgt_i8, cgtCPU );
      inptup->setitem(0, arg0);

      long *ardata = get_0_int(inptup) ;
      long *inpnum = get_0_int(newargs) ;


      *ardata = (*inpnum) * 2 ;

      return inptup ;

    }

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
};



