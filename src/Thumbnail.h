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
#include "Utils.h"

class Thumbnail : public ofxMSAInteractiveObject{
    ofVec2f dimensions;
    ofVboMesh vbo;
    enum {} animation_state;
    int elapsed;
    
public:
    
    Thumbnail(){}
    Thumbnail(){
        
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

};