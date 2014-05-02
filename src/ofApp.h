
#pragma once
#include "ofMain.h"
#include "pen.h"

#define NUM 100

class ofApp : public ofBaseApp{
public:
    
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    unsigned char* pixels;
    int pos;
    int red;
    int green;
    int blue;
    
    ofFbo fbo;
    ofFbo processFbo;
    ofImage image;
    
    pen pens[NUM];
    
};
