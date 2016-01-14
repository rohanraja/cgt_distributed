#include "trainingJob.h"
#include <sstream>

void signalHandler(int sig){

    cout << "\nGot Signal #" << sig << "\n" ;
    TrainingJob::instance->gracefullyExit();
}
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
    
    signal(31, &signalHandler);
    signal(SIGINT, &signalHandler);
    signal(SIGKILL, &signalHandler);
    
    TrainingJob job(dir);
    job.train();
    
    
    
    return 0;
    
}
