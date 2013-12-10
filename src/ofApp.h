#pragma once

#include "ofMain.h"
#include "ofxMSATimer.h"
#include "genUtils.h"
#include "genSignal.h"
#include "genParam.h"

class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
private:
    ofVboMesh waveform, preview;
    ofxMSATimer timer;
    PrefVector<Signal> prefs;
    NoiseWrapper noise;
    ofColor waveformColor, lineColor;

    float ballSize;
    int time;
    
    struct {
        float waveformWindowWidth, waveformWindowHeight;
        int waveformNumSegments;
        float vocabWindowWidth, vocabWindowHeight;
        
        float pxVocabThumbnailSize;
        float defaultIndent;
        float msSampleSize, msScreenSampleLength;
    } params;

};


