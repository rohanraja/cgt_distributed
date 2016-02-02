#include "trainingJob.h"
#include <sstream>
#include <fenv.h>
#include <math.h>

int main(int argc, char *args[] ){
    
//    signal(SIGINT, signalHandler);
 
    
    string inpfile = "test.inp" ;
    string schedFile = "test.bin" ;
    if(argc >= 2){
        inpfile = args[1];
    }
    
    if(argc >= 3){
        schedFile = args[2];
    }

    Interpreter * inp = interpreter_from_file((char*)(inpfile.c_str()));
    ARGVEC trainSched = get_schedule(schedFile);
    
    if(trainSched.size() > 0){
      rep(i, trainSched.size()){

      TIMECH("Single Run")
        run_print(inp, trainSched[i]);

      }
    }
    else{
      TIMECH("Single Run")
        run_print(inp, new cgtTuple(0) , true);
    }
    
    return 0;
    
}
