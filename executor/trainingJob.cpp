//
//  trainingJob.cpp
//  distX
//
//  Created by Rohan Raja on 04/01/16.
//  Copyright (c) 2016 Rohan Raja. All rights reserved.
//

#include "trainingJob.h"

void run_print(Interpreter * inp, cgtTuple * inptup, bool isPrint ){
    
    if(inp ==NULL)
        return;
    
    if(isPrint)
        cout << "\n*************************************************\nResults:\n" ;
    IRC<cgtTuple> ret = IRC<cgtTuple> (inp->run(inptup)) ;
    cgtTuple *res = ret.get();
    if(isPrint)
        res->print();
}


int TrainingJob::tst = 0;
TrainingJob* TrainingJob::instance = NULL;


