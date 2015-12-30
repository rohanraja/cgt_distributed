#include "egreader.h"
#include <iostream>
#include <fstream>

using namespace cgt ;
using namespace std ;


ExecutionGraph * read_eg(ifstream &f){

  long nargs, nlocs ;

  readf(f, nargs);
  readf(f, nlocs);

  trace(nargs);
  trace(nlocs);
  
  vector<Instruction *> instrs = loadInstVector(f);

  f.close();

  return new ExecutionGraph(instrs, nargs, nlocs) ;
}

Interpreter * interpreter_from_file2(char *fname){


  ifstream f;
  f.open("eg.bin" , ios::binary | ios::in);

  vector<MemLocation> outps = loadMemVector(f);
  ExecutionGraph *eg = loadExecutionGraph(f) ;

  Interpreter * inp = create_interpreter(eg,outps,0);

  return inp;
  return new DummyInterpreter(fname) ;

}

long * get_0_int(cgtTuple *inptup){

  long *ardata = (long*) (((cgtArray*)(inptup->getitem(0)))->data()) ;

  return ardata ;

}
