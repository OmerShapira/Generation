#pragma once

#include "ofMain.h"
#include "ofxMSATimer.h"
#include "Utils.h"


class prefVector : public vector<pair<int, float> >{     //TODO: remove support for deletes
private: int lastAddedIndex;
public:
    void updateAdded(){ lastAddedIndex = this->size() - 1; }
    bool hasChanged(){ return (lastAddedIndex > 0) && (lastAddedIndex != this->size() - 1);}
    vector<pair<int, float> >::iterator fromLastUpdated(){ return (this->begin() + lastAddedIndex);}
};


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
    prefVector prefs;
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


