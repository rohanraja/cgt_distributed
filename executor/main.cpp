#include "egreader.h"
#include "helpers.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<dlfcn.h>

using namespace cgt ;

int nloops = 1;

void run_dummy(Interpreter * inp){

  cgtTuple *inptup = new cgtTuple(1);
  
  static long shape[1] = {1};

  static cgtArray *arg0 = new cgtArray(1, shape, cgt_i8, cgtCPU );
  inptup->setitem(0, arg0);

  float *ardata = (float*) get_0_int(inptup) ;

  *ardata = 5 ;

  

  std::cout << "\nInput = " <<  *ardata << "" ;
  for(int i=0; i<nloops; i++) {

    IRC<cgtTuple> ret = IRC<cgtTuple> (inp->run(inptup)) ;
    cgtTuple *res = ret.get();
    res->print();

  }

}

void run_print(Interpreter * inp, cgtTuple * inptup){

    IRC<cgtTuple> ret = IRC<cgtTuple> (inp->run(inptup)) ;
    cgtTuple *res = ret.get();
    res->print();
}

void run_scheduled(Interpreter * inp){

  ifstream f ;
  f.open("run_sched.bin", ios::binary | ios::in);

  cgtTuple *args = new cgtTuple(f);
  args->print();
  f.close();
}

int main(int argc, char *args[] ){

  if(argc > 1){
    std::stringstream convert(args[1]);
    convert >> nloops ;
  }
  Interpreter * inp = interpreter_from_file((char*)"eg.bin");

  run_scheduled(inp);
  // run_dummy(inp);

  return 0;

}
