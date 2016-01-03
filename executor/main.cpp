#include "egreader.h"
#include "helpers.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<dlfcn.h>
#include <unistd.h>

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

void run_print(Interpreter * inp, cgtTuple * inptup, bool isPrint = true){

    if(isPrint)
      cout << "\n*************************************************\nResults:\n" ;
    IRC<cgtTuple> ret = IRC<cgtTuple> (inp->run(inptup)) ;
    cgtTuple *res = ret.get();
    if(isPrint)
      res->print();
}

void run_scheduled(Interpreter * inp){

  ifstream f ;
  f.open("run_sched.bin", ios::binary | ios::in);

  bool running = true ;
  while(running){
    try{
      cgtTuple *args = new cgtTuple(f);
      cout << "\n##################################################\nArguments:\n" ;
      // args->print();
      run_print(inp, args);
    }
    catch(int){
      running = false ;
    }
  }

  f.close();
}

#define ARGVEC vector<cgtTuple*>
ARGVEC get_schedule(const string &fname){
  
  ARGVEC outp ;
  ifstream f ;
  f.open(fname.c_str(), ios::binary | ios::in);
  if(!f.good())
    return outp;

  bool running = true ;
  while(running){
    try{
      cgtTuple *args = new cgtTuple(f);
      outp.push_back(args);
    }
    catch(int){
      running = false ;
    }
  }
  f.close();

  return outp ;
}

void save_outp(Interpreter * inp, cgtTuple * inptup, ofstream &f){

    IRC<cgtTuple> ret = IRC<cgtTuple> (inp->run(inptup)) ;
    cgtTuple *res = ret.get();
    res->save(f);

}
void masterInterpreter_Run(){

  Interpreter * mainInt;
  mainInt = create_main_interpreter(100); // TODO: Make Dynamic

  Interpreter * paramRes = interpreter_from_file((char*)"paramResume.inp");
  Interpreter * trinp = interpreter_from_file((char*)"train.inp");
  Interpreter * valinp = interpreter_from_file((char*)"valid.inp");
  Interpreter * paraminp = interpreter_from_file((char*)"param.inp");




  ARGVEC trainSched = get_schedule("train_sched.bin");
  ARGVEC validSched = get_schedule("valid_sched.bin");
  ARGVEC paramResumeSched = get_schedule("params_out");

  rep(j, paramResumeSched.size()){
    run_print(paramRes, paramResumeSched[j], false);
    }

  ofstream f;

  rep(i, nloops){
    rep(j, trainSched.size()){

      run_print(trinp, trainSched[j], false);
    }

    rep(j, validSched.size()){
      run_print(valinp, validSched[j]);
    }

    f.open("params_out", ios::binary | ios::out);
    cgtTuple *blankInp = new cgtTuple(0);
    save_outp(paraminp, blankInp, f);
    f.close();
  }


}

int main(int argc, char *args[] ){
    
    chdir("../examples/");

  if(argc > 1){
    std::stringstream convert(args[1]);
    convert >> nloops ;
  }
  masterInterpreter_Run();

  return 0;

}
