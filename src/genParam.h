//
//  genParam.h
//  Generation
//
//  Created by Omer Shapira on 01/12/13.
//
//

#pragma once
#include <iostream>
#include "ofMain.h"
#include "genSignal.h"

using namespace std;

using namespace gen;    

    template <typename T>
    class PrefVector {
    private:
        int lastAddedIndex;
        vector<Param> prefs;
    public:
        void updateAdded(){ lastAddedIndex = prefs.size() - 1; }
        bool hasChanged(){ return (lastAddedIndex > 0) && (lastAddedIndex != prefs.size() - 1);}
        typename vector<Param>::iterator fromLastUpdated(){ return (prefs.begin() + lastAddedIndex);}
        int size(){return prefs.size();}
        bool empty(){return prefs.empty();}
        Param operator[](int i){return prefs[i];} //FIXME: Check if this is returning Param or T
        void push_back(Param p){prefs.push_back(p);}
        void pop_back(){prefs.pop_back();}
    };
    
