#include "pen.h"

pen::pen(){
    
    centx = ofRandom(0,850);
    centy = ofRandom(0,422);
    radius = ofRandom(5,20);
    rotate = ofRandom(-5,10);
    lastx = -999;
    lasty = -999;
    
    radiusNoise = ofRandom(10);
    spiral = ofRandom(1.5);
    waitCnt = ofRandom(0, 100);
    step = 0;
    
}

//--------------------------------------------------------------
void pen::setR(int red){
    r = red;
}

//--------------------------------------------------------------
void pen::setG(int green){
    g = green;
}

//--------------------------------------------------------------
void pen::setB(int blue){
    b = blue;
}

//--------------------------------------------------------------
void pen::update(){

    ang += rotate;
    radius += spiral;
    radiusNoise += 5;

}
//--------------------------------------------------------------
void pen::draw(){

    ofEnableAlphaBlending();

    if (step < waitCnt) {
        step++;
    }
    else {
        
        float thisRadius = radius + ofRandom(ofNoise(radiusNoise) * 50) - 25;
        
        
        if ((ang < 360*5) || (ang > -360*5) ) {
            
            x = centx + (thisRadius * cos(ang*3.141592/180));
            y = centy + (thisRadius * sin(ang*3.141592/180));
            
            if (lastx > -999) {
                ofSetColor(r,g,b);
                ofSetLineWidth(5);
                ofLine(x, y, lastx, lasty);
            }
            
            lastx = x;
            lasty = y;
            
        }
    }
}






