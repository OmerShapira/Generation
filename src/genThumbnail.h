//
//  Thumbnail.h
//  Generation
//
//  Created by Omer Shapira on 08/12/13.
//
//

#pragma once

#include "ofxMSAInteractiveObject.h"
#include "ofMain.h"
#include "genUtils.h"
#include "genParam.h"
#include "genSignal.h"

using namespace gen;


class Thumbnail : public ofxMSAInteractiveObject{
    ofVec2f dimensions;
    ofVboMesh vbo;
    
    CompoundSignal parentSignal; //FIXME: This needs to not have generics
    Param param;
    
public:
    
    Thumbnail(Param p): param(p){
        for (int i = 0; i < width ; i++){ //TODO: make this adaptive resolution
            vbo.setMode(OF_PRIMITIVE_LINE_STRIP);
            float x = ofMap(i, 0, width, param.position, param.position + param.msLength);
            const Signal& func = param.func;
            vbo.addVertex(ofPoint(i, height * (1.0 - func(x))));
        }
    }
    
    void setup() {
        enableMouseEvents();
    }
    
    void exit() {
        
    }
    
    void update() {

    }
    
    void draw() {
        vbo.draw();
    }
    
    
    virtual void onRollOver(int x, int y) {
    }
    
    virtual void onRollOut() {
    }
    
    virtual void onMouseMove(int x, int y){
    }
    
    virtual void onDragOver(int x, int y, int button) {
    }
    
    virtual void onDragOutside(int x, int y, int button) {
    }
    
    virtual void onPress(int x, int y, int button) {
    }
    
    virtual void onRelease(int x, int y, int button) {
        
    }
    
    virtual void onReleaseOutside(int x, int y, int button) {
        
    }
    
    virtual void keyPressed(int key) {
        
    }
    
    virtual void keyReleased(int key) {
        
    }
    
private:
    Thumbnail(){};
};
