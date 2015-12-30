#include "egreader.h"
#include<iostream>
#include<vector>
#include<sstream>
#include<dlfcn.h>

using namespace cgt ;




int main(int argc, char *args[] ){

  Interpreter * inp = interpreter_from_file((char*)"eg.bin");

  cgtTuple *inptup = new cgtTuple(1);
  
  static long shape[1] = {1};

  static cgtArray *arg0 = new cgtArray(1, shape, cgt_i8, cgtCPU );
  inptup->setitem(0, arg0);

  float *ardata = (float*) get_0_int(inptup) ;

  *ardata = 5 ;

  int nloops = 1;
  if(argc > 1){
    std::stringstream convert(args[1]);
    convert >> nloops ;
  }
  

  std::cout << "\nInput = " <<  *ardata << "" ;
  for(int i=0; i<nloops; i++) {

    IRC<cgtTuple> ret = IRC<cgtTuple> (inp->run(inptup)) ;
    cgtTuple *res = ret.get();
    // cgtTuple *res = inp->run(inptup);

    float *resData = (float *) get_0_int(res);

    std::cout << "\nResult = " <<  *resData  ;
  }

  return 0;

}
