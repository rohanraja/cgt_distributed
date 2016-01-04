#include "trainingJob.h"
#include <sstream>


int main(int argc, char *args[] ){
    
//    signal(SIGINT, signalHandler);
    
    string dir = "../examples" ;
    if(argc >= 2){
        dir = args[1];
    }
    
    int nloops = 1;
    
    if(argc == 3){
        std::stringstream convert(args[2]);
        convert >> nloops ;
    }
    
    TrainingJob job(dir);
    job.train();
    
    
    
    return 0;
    
}
