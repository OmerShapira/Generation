//
//  genParam.h
//  Generation
//
//  Created by Omer Shapira on 01/12/13.
//
//

#pragma once
#include <iostream>

using namespace std;

template <class T>
class Param {
public:
    Param(T param, float position, float msLength, string name): position(position), msLength(msLength), param(param), name(name){}
    Param<T>& operator=( Param<T> &rhs ) {}
    const float position;
    const float msLength;
    const T param;
    const string name;
};


template <typename T>
class PrefVector {
private:
    int lastAddedIndex;
    vector<Param<T> > prefs;
public:
    void updateAdded(){ lastAddedIndex = prefs.size() - 1; }
    bool hasChanged(){ return (lastAddedIndex > 0) && (lastAddedIndex != prefs.size() - 1);}
    typename vector<Param<T> >::iterator fromLastUpdated(){ return (prefs.begin() + lastAddedIndex);}
    int size(){return prefs.size();}
    bool empty(){return prefs.empty();}
    Param<T> operator[](int i){return prefs[i];} //FIXME: Check if this is returning Param or T
    void push_back(Param<T> p){prefs.push_back(p);}
    void pop_back(){prefs.pop_back();}
};

