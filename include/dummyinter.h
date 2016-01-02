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
        return NULL;

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


