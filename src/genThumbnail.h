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

class Thumbnail : public ofxMSAInteractiveObject{
    ofVec2f dimensions;
    ofVboMesh vbo;
    
    
    CompoundSignal parentSignal;
    Param<Signal> param;
    
public:
    
    Thumbnail(Param<Signal> p): param(p){
        for (int i = 0; i < width ; i++){ //TODO: make this adaptive resolution
            vbo.setMode(OF_PRIMITIVE_LINES);
            vbo.addVertex(ofPoint());
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