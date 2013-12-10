//
//  GenSignal.h
//  Generation
//
//  Created by Omer Shapira on 08/12/13.
//
//

#pragma once
#include "ofMain.h"
#include <sys/time.h>

//#include "genParam.h"
using namespace std;

namespace gen{
    
    class Param;
    
    class Signal{
    public:
        Signal(){}
        virtual float operator()(float t){ return 0; }
        virtual float operator()(){ return 0; }
        virtual Signal& operator<<(float value){} //TODO: Turn into params
        virtual void lockStream(){} //TODO: Maybe remove? So confuse
        virtual ~Signal(){}
    };
    
    // ======================================================= //
    class Zero : public Signal{ //TODO: This is not necessary
        virtual float operator()(float t){ return 0; }
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
    
    class Param {
    public:
        Param(Signal func, float position, float msLength, string name): ID(ofGetSystemTimeMicros()), position(position), msLength(msLength), func(func), name(name){
        }
        const long ID;
        //TODO: Make this consts.
        Param& operator=( Param &rhs ) {}
        const float position;
        const float msLength;
         Signal func;
        const string name;
        
        int operator<(Param& p){return ID < p.ID;}
        int operator>(Param& p){return ID > p.ID;}
        bool operator==(Param& p){return ID == p.ID;}
    private:
//        Param(){}
    };
    
    // ======================================================= //
    
    
    class CompoundSignal : public Signal {
        typedef pair<Param, int> value_type;
        map<Param, int> params;
        bool locked;
        float normalizationCoef;
        
    public:
        CompoundSignal(){
            locked = false;
            Zero z;
            params.insert(pair<Param, int>(Param(z, 0, 1, "Zero"), 0));
        }
        
        virtual ~CompoundSignal(){}
        /*
         << as vote
         */
        CompoundSignal& operator<<(Param param){
            auto value = params.find(param);
            if (value == params.end()){
                params.insert(value_type(param, 1));
            } else {
                value->second = value->second + 1;
            }
            return *this;
        }
        
        void updateAndLock(){
            if (!locked){
                float sum = 0;
                for (auto& kv : params){
                    sum += kv.second;
                }
                normalizationCoef = 1 / sum;
            }
            locked = true;
        }
    };

    
}