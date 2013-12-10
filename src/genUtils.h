//
//  genUtils.h
//  Generation
//
//  Created by Omer Shapira on 01/12/13.
//
//

#pragma once
#include "ofMath.h"
class Utils{
    
public:
    /* Quadratic B-Spline
     * https://en.wikipedia.org/wiki/B-spline
         :<math>B_1=x^2/2 \qquad 0 \le x \le 1</math>
         :<math>B_2=(-2x^2+6x-3)/2 \qquad 1 \le x \le 2</math>
         :<math>B_3=(3-x)^2/2 \qquad 2 \le x \le 3</math>
     */
    static float bSpline (float t, float min, float max){
        float ret;
        if ((min > max) || (!ofInRange(t, min, max))) {
            ret = 0;
        } else {
            float val = ofMap(t, min, max, 0, 3);
            
            if (ofInRange(val, 0, 1)){
                ret = val * val * 0.5;
            } else if (ofInRange(val, 1, 2)) {
                ret = (val * val * (-2.) + 6 * val - 3.) * 0.5;
            } else {
                float tmp = (3. - val);
                ret = tmp * tmp * 0.5;
            }
        }
        return ret;
    }
    
    static float noise (float t, float oct1, float oct2=0, float oct3=0, float oct4=0){
        return oct1 * ofNoise(t) + oct2 * ofNoise(2 * t) + oct3 * ofNoise(4 * t) + oct4 * ofNoise(8 * t);
    }
   
};