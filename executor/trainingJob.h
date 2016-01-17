//
//  trainingJob.h
//  distX
//
//  Created by Rohan Raja on 04/01/16.
//  Copyright (c) 2016 Rohan Raja. All rights reserved.
//

#ifndef __distX__trainingJob__
#define __distX__trainingJob__

#include <stdio.h>
//#include "egreader.h"
#include "helpers.h"
#include "execution.h"
#include <unistd.h>
#include<vector>
#include<sstream>
#include<signal.h>

using namespace cgt ;


void run_print(Interpreter * inp, cgtTuple * inptup, bool isPrint = true);


struct TrainingStatus{
    
};

class TrainingJob{
    
    Interpreter * paramLoader ;
    Interpreter * paramSaver ;
    Interpreter * trainer ;
    Interpreter * validator ;
    
    ARGVEC trainSched;
    ARGVEC validSched;
    
    string folderPath;
    
    
    static int tst ;
    
    int currentEpoch = 0;
    int currentBatch = 0;
    bool isExiting = false;
    int numEpochs = 20 ;
    float last_accuracy = 0;
    
public:
    static TrainingJob *instance ;
    
    TrainingJob(string pFolderName){
        
        folderPath = pFolderName + "/" ;
        chdir(folderPath.c_str());
        
        instance = this ;
//        signal(SIGINT, signalHandler) ;
//        signal(SIGINFO, signalHandler) ;
//        signal(30, signalHandler) ;
//        signal(31, signalHandler) ;
        
        loadInterpreters();
        loadSchedule();
        
        
    }
    
    static void signalHandler(int sig){
        
        switch (sig) {
            case SIGINT:
                instance->gracefullyExit();
                break;
            case 30:
                instance->sendStatus();
                break;
            case 31:
                instance->gracefullyExit();
                break;
        }
    }
    
    void sendStatus(){
        
        cerr << "Current Batch:" << currentBatch << "\n" ;
        
    }
    
    void gracefullyExit(){
        
        cout << "\nGracefully Exiting CGT\n";
        isExiting = true;
    }
    void saveState(){
        
        saveParams();
        ofstream f ;
        f.open(folderPath + "state.bin", ios::binary | ios::out);
        writef(f, currentEpoch);
        writef(f, currentBatch);
        cout << "\nSaving State:\n";
        trace(currentBatch);
        trace(currentEpoch);
        f.close();
        
    }
    
    void loadState(){
        
        loadParams();
        ifstream f ;
        f.open(folderPath + "state.bin", ios::binary | ios::in);
        
        if( !f.good() )
            return;
        
        readf(f, currentEpoch);
        readf(f, currentBatch);
        
        cout << "\nResuming State:\n";
        trace(currentBatch);
        trace(currentEpoch);
        f.close();
        
    }
    void loadInterpreters(){
        paramLoader = loadInt("paramResume.inp");
        paramSaver = loadInt("param.inp");
        trainer = loadInt("train.inp");
        validator = loadInt("valid.inp");
    }
    
    void loadParams(){
        
        ARGVEC paramResumeSched = get_schedule(folderPath + "params_out");
        
        rep(j, paramResumeSched.size()){
            run_print(paramLoader, paramResumeSched[j], false);
        }
    }
    
    void saveParams(){
        
        ofstream f ;
        f.open(folderPath + "params_out", ios::binary | ios::out);
        cgtTuple *blankInp = new cgtTuple(0);
        IRC<cgtTuple> ret = IRC<cgtTuple> (paramSaver->run(blankInp)) ;
        cgtTuple *res = ret.get();
        res->save(f);
        f.close();
        
    }
    
    void saveStatus(){
        
        ofstream f ;
        f.open(folderPath + "log", ios::binary | ios::app);
        f << currentEpoch << endl;
        f << last_accuracy << endl;
        f.close();
        
    }
    void validate(){
//        rep(j, validSched.size()){
        rep(j, 1){
//            run_print(validator, validSched[j]);
            
            IRC<cgtTuple> ret = IRC<cgtTuple> (validator->run(validSched[j])) ;
            cgtTuple *res = ret.get();
            float * fdata = (float *) (((cgtArray*)(res->getitem(0)))->data()) ;
            last_accuracy = *fdata ;
            cout << "Accuracy: " << last_accuracy << "\n";
        }
    }
    void loadSchedule(){
        trainSched = get_schedule(folderPath + "train_sched.bin");
        validSched = get_schedule(folderPath + "valid_sched.bin");
    }
    
    Interpreter *loadInt(string fname){
        string intName = folderPath + fname ;
        return interpreter_from_file((char*)(intName.c_str()));
    }
    
    void trainLoop(){
        
        int j = currentBatch;
//        for(; j<1; j++){
        for(; j<trainSched.size(); j++){
            currentBatch = j;
            if(isExiting)
                return;
            run_print(trainer, trainSched[j], false);
        }
        currentBatch = 0;
    }
    
    void train(){
        
        loadState();
        
        for(int i=currentEpoch; i<numEpochs; i++){
            
            currentEpoch = i;
            
            trainLoop();
            
            validate();
            
            if(currentBatch == 0)
                currentEpoch ++ ;
            
            saveState();
            saveStatus();
            
            if(isExiting)
                return;
            
        }
    }
    
    
};


#endif /* defined(__distX__trainingJob__) */
