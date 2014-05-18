#include "pen.h"

pen::pen(){
    
    centx = ofRandom(1440);
    centy = ofRandom(900);
    radius = ofRandom(0, 200);
    rotate = ofRandom(-3, 3);
    
    if (rotate == 0) {
        rotate = 1;
    }
    
    lastx = -999;
    lasty = -999;
    
    radiusNoise = ofRandom(10);
    //    spiral = ofRandom(-0.5, 0.5);
    waitCnt = ofRandom(0, 100);
    step = 0;
    
    sw = ofRandom(5,8);
    col = ofRandom(20);
    a = ofRandom(0, 255);
    waiting = ofRandom(0,80);
    
    speedX = ofRandom(-3,3);
    speedY = ofRandom(-2,2);
    
    centx_ = ofRandom(1440);
    centy_ = ofRandom(900);
    radius_ = ofRandom(20);
    noiseVal = ofRandom(10);
    
}

//--------------------------------------------------------------
void pen::setup(){
    
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
    radiusNoise += ofRandom(-0.05, 0.05);
    radius += ofRandom(-0.5, 0.5);
    
    
    if (flag_r == false) {
        r += 0.1;
        g += 0.1;
        b += 0.1;
        if (r >= 255 || g >= 255 || b >= 255) {
            flag_r = true;
        }
    }else if(flag_r == true){
        r -= 0.1;
        g -= 0.1;
        b -= 0.1;
        if (r <= 0 || g <= 0 || b <= 0) {
            flag_r = false;
        }
    }
    
    if(waiting < 80){
        waiting++;
    }else{
        if(a > 30){ a --; }else{ a = 255;}
    }
    
    
    
    if (radiusNoise >= 5) {
        radiusNoise = 0;
    }
    
    
    if(radius >= 500){
        spiral = -spiral;
    }else if (radius <= 0){
        spiral = -spiral;
    }
    
    
    if(noiseVal >= 20){
        noiseVal = ofRandom(10);
    }
    
    
    centx += speedX;
    centy += speedY;
    if (centx >= 1990 || centx <= 0) {
        speedX = speedX*-1;
    }
    if (centy >= 950 || centy <= 0) {
        speedY = speedY*-1;
    }
    
}
//--------------------------------------------------------------
void pen::draw(){
    
    ofFill();
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    
    
    if (step < waitCnt) {
        step++;
    }
    else {
        
        float thisRadius = radius + (ofNoise(radiusNoise) * 200) -100;
        
        
        if ((ang >= 0 && ang < 360) || (ang <= 0 && ang > -360) ) {
            
            x = centx + (thisRadius * cos(ang*3.1415926/180));
            y = centy + (thisRadius * sin(ang*3.1415926/180));
            
            if (lastx > -999) {
                //                if (col == 0) {
                //                    ofSetColor(225, 88, 52);
                //                }else if (col == 1){
                //                    ofSetColor(127, 164, 94);
                //                }else if (col == 2){
                //                    ofSetColor(239, 243, 193);
                //                }
                //                else{
                ofSetColor(r+30, g+30, b+30, a);
                //                }
                ofSetLineWidth(sw);
                ofLine(x, y, lastx, lasty);
                
            }
            
            lastx = x;
            lasty = y;
            
        }else{
            
            ofBeginShape();
            ofSetColor(r+30, g+30, b+30, a);
            for (float ang=0; ang <= 360; ang++) {
                
                noiseVal += 0.05;
                thisRadius_ = radius_ + (ofNoise(noiseVal)*10)-5;
                x_ = centx_ + (thisRadius_ * cos(ang * 3.1415926/180));
                y_ = centy_ + (thisRadius_ * sin(ang * 3.1415926/180));
                ofCurveVertex(x_, y_);
                
            }
            
            ofEndShape();
            reset();
            
        }
        
    }
    
}

//--------------------------------------------------------------
void pen::reset(){
    
    lastx = -999;
    lasty = -999;
    
    centx = ofRandom(1440);
    centy = ofRandom(900);
    radius = ofRandom(100);
    rotate = ofRandom(-5, 5);
    
    if (rotate == 0) {
        rotate = 1;
    }
    
    radiusNoise = ofRandom(10);
    spiral = ofRandom(-0.5, 0.5);
    waitCnt = ofRandom(0, 100);
    step = 0;
    
    col = ofRandom(20);
    a = ofRandom(0, 255);
    waiting = ofRandom(0,80);
    
    speedX = ofRandom(-2,2);
    speedY = ofRandom(-2,2);
    
}


