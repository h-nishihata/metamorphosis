#include "pen.h"

pen::pen(){
    
    x = ofGetWidth();
    y = ofRandom(ofGetHeight()/2-30, ofGetHeight()/2+30);
    rad = ofRandom(1,3);
    a = 255;
}

//--------------------------------------------------------------
void pen::update(){
    
    int posx = ofRandom(-1,-5);
    int posy = ofRandom(-1,1);
    x += posx;
    y += posy;
    a--;
    
}
//--------------------------------------------------------------
void pen::draw(){
    
    ofEnableAlphaBlending();
    
    ofSetColor(r,g,b);
    ofCircle(x, y, rad);

    
}