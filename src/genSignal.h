//
//  GenSignal.h
//  Generation
//
//  Created by Omer Shapira on 08/12/13.
//
//

#pragma once
#include "ofMain.h"
#include "Param.h"
//#include <iostream>
//#include <vector>

using namespace std;

class Signal{
    
public:
    virtual float operator()(float t){}
    virtual Signal& operator<<(float value){} //TODO: Turn into params
    virtual void lockStream(){} //TODO: Maybe remove? So confuse
    virtual ~Signal(){}
};

// ======================================================= //


class NoiseWrapper : public Signal {
    bool locked;
    bool normalize;
    vector<float> coefs;
public:
    NoiseWrapper(){}
    virtual float operator()(float t){
        float sum = 0;
        for (int i = 0 ; i < coefs.size(); i ++ ){
            sum += coefs[i] * ofNoise( t * ((i > 0) ? i * 2 : 1));
        }
        if (normalize){
            sum /= getNormalizationCoef();
        }
        return sum;
    }
    virtual NoiseWrapper& operator<<(float coef){
        coefs.push_back(coef);
        return *this;
    }
    virtual void lockStream(){
        getNormalizationCoef(); //refresh value
        locked = true;
    }
    void setNormalized(bool b){ normalize = b; }
    vector<float>& getCoefs(){ return coefs; }
    
private:
    float normalizationCoef;
    float getNormalizationCoef(){
        if (locked && normalizationCoef != 0){
            return normalizationCoef;
        } else {
            normalizationCoef = 0;
            for (float f : coefs){
                normalizationCoef += f;
            }
        }
    }
};

// ======================================================= //

template <class T>
class CompoundSignal : public Signal {
    typedef pair<Param<T>, int> value_type;
    map<Param<T>, int> params;
    bool locked;
    
public:
    virtual ~CompoundSignal(){}

    /*
     << as vote
     */
    CompoundSignal<T>& operator<<(Param<T> param){
        auto value = params.find(param);
        if (*value == params.end()){
            params.insert(value_type(param, 1));
        } else {
            value->second = value->second + 1;
        }
        return this;
    }
    
    void updateAndLock(){
        if (!locked){
            float sum = 0;
            for (auto& kv : params){
                sum += kv.second;
            }
        }
    }
};