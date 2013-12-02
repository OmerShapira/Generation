//
//  Param.h
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
    Param(T param, float msLength, string name): _msLength(msLength), _param(param), _name(name){}
    const float _msLength;
    const T _param;
    const string _name;
};
