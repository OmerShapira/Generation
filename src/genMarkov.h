//
//  genMarkov.h
//  Generation
//
//  Created by Omer Shapira on 01/12/13.
//
//

#pragma once
#include <iostream.h>
#include "genParam.h"

namespace gen{
    
    template <class T>
    class MarkovChain {
        
    public:
        unsigned long position() const{return _position}
        //    void seek(unsigned long pos){} //TODO: Should I implement this?
        Param<T> get();
        void vote(Param<T> p);
        
    private:
        unsigned long _position;
        list< pair<Param<T>, float> > grammar; //Right now grammar is unstructured
        
    };
}