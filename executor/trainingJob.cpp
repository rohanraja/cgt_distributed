//
//  trainingJob.cpp
//  distX
//
//  Created by Rohan Raja on 04/01/16.
//  Copyright (c) 2016 Rohan Raja. All rights reserved.
//

#include "trainingJob.h"

void run_print(Interpreter * inp, cgtTuple * inptup, bool isPrint ){
    
    if(isPrint)
        cout << "\n*************************************************\nResults:\n" ;
    IRC<cgtTuple> ret = IRC<cgtTuple> (inp->run(inptup)) ;
    cgtTuple *res = ret.get();
    if(isPrint)
        res->print();
}

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