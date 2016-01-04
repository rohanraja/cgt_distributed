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

using namespace cgt ;


void run_print(Interpreter * inp, cgtTuple * inptup, bool isPrint = true);

ARGVEC get_schedule(const string &fname);

class TrainingJob{
    
    Interpreter * paramLoader ;
    Interpreter * paramSaver ;
    Interpreter * trainer ;
    Interpreter * validator ;
    
    ARGVEC trainSched;
    ARGVEC validSched;
    
    string folderPath;
    
    int currentEpoch = 0;
    int currentBatch = 0;
    int numEpochs = 4;
    
public:
    
    TrainingJob(string pFolderName){
        
        folderPath = pFolderName + "/" ;
        chdir(folderPath.c_str());
        
        loadInterpreters();
        loadSchedule();
        
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
        f.open("params_out", ios::binary | ios::out);
        cgtTuple *blankInp = new cgtTuple(0);
        IRC<cgtTuple> ret = IRC<cgtTuple> (paramSaver->run(blankInp)) ;
        cgtTuple *res = ret.get();
        res->save(f);
        f.close();
        
    }
    
    void validate(){
        rep(j, validSched.size()){
            run_print(validator, validSched[j]);
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
        
            for(int j=currentBatch; j<trainSched.size(); j++){
                run_print(trainer, trainSched[j], false);
            }
    }
    
    void train(){
        
        for(int i=currentEpoch; i<numEpochs; i++){
            
            trainLoop();
            
            validate();
            
            saveParams();
            
        }
    }
    
    
};

#endif /* defined(__distX__trainingJob__) */
