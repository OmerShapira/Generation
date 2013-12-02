#include "ofApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    params.defaultIndent= 10;
    params.waveformWindowHeight= 300;
    params.waveformNumSegments= 500;
    params.vocabWindowHeight= 600;
    params.msScreenSampleLength=6000;
    params.msSampleSize = 3000;
    
    ofBackground(40);
    waveform.setMode(OF_PRIMITIVE_LINE_STRIP);
    preview.setMode(OF_PRIMITIVE_LINE_STRIP);
    waveformColor = ofColor(170, 40, 40);
    lineColor = ofColor::seaGreen;
    
    //Set Noise
    (noise << 0.5 << 0.0 << 0.125).lockStream(); //Remind myself to always write code this way
    noise.setNormalized(true);
}

//--------------------------------------------------------------
void testApp::update(){

    params.waveformWindowWidth = ofGetWidth();
    params.vocabWindowWidth = ofGetWidth();
    
    waveform.clear();
    time = timer.getAppTimeMillis();
    float resolution  = 0.01;
    float amplitude = 200;
    
    //number of segments dictates number of milliseconds of lookahead
    float lengthFactor = params.msScreenSampleLength/params.waveformNumSegments;
    
    for (int i = -params.waveformNumSegments/2 ; i < params.waveformNumSegments/2; i++) {
        float x = ofMap(i, -params.waveformNumSegments/2, params.waveformNumSegments/2, 0, ofGetWidth());
        float y = params.waveformWindowHeight - noise((time + i * lengthFactor) * resolution) * amplitude;
        if (i==0) {ballSize = ofNoise(time * resolution) * amplitude/2.;}
        waveform.addVertex(ofPoint(x,y));
    }
    
    if (prefs.size() > 0) {
        preview.clear();
        pair<int, float> data = prefs[0];
        int segments = 50;
        for (int i = 0 ; i < segments ; i++){
            float x = ofMap(i, 0, segments, 0, 100); //FIXME: MAGICK NUMBER
            float y = 100 - noise((data.first + i * lengthFactor) * resolution) * amplitude;
            preview.addVertex(ofPoint(x,y));
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofPushStyle();{
        float msSegmentLength = params.msScreenSampleLength / params.waveformNumSegments;
        int segmentsSampleLength = ceil(params.msSampleSize / (msSegmentLength/2.)); //FIXME: YER MATH IS WRANG
        float pxSegmentLength = params.waveformNumSegments / params.waveformWindowWidth;
        float pxSampleWindowWidth = segmentsSampleLength * pxSegmentLength;
        
        ofSetColor(lineColor.r, lineColor.g, lineColor.b, 50);
        ofSetRectMode(OF_RECTMODE_CORNER);
    
        ofRect(ofGetWidth()/2. - pxSampleWindowWidth, 0 , pxSampleWindowWidth, params.waveformWindowHeight);
        ofSetColor(lineColor);
        ofNoFill();
        ofRect(ofGetWidth()/2. - pxSampleWindowWidth, 0 , pxSampleWindowWidth, params.waveformWindowHeight);
    }ofPopStyle();
    
    ofSetColor(waveformColor);
    waveform.draw();
    ofCircle(ofGetWidth()/2., 600, ballSize);
    
    ofSetColor(ofColor::seaGreen);
    ofLine(ofGetWidth()/2., 0 , ofGetWidth()/2., params.waveformWindowHeight);
    
    ofPushMatrix();
    ofTranslate(params.waveformWindowHeight, params.waveformWindowHeight*2);
    ofSetColor(waveformColor);
    preview.draw();
    ofPopMatrix();
    
}














//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch (key) {
            
        case 'p':
            //FIXME: This will not be accurate]
            prefs.push_back(pair<int, float>(time - params.msSampleSize, 0.5));
            break;
        case 'f':
            ofToggleFullscreen();
            break;
            
        default:
            break;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}