#include "pen.h"

pen::pen(){
    
    centx = ofNoise(ofRandom(10)) * 1340 + 100;
    centy = ofNoise(ofRandom(10)) * 800 + 100;
    radius = ofRandom(5,20);
    rotate = ofRandom(-1,1);
    
    if (rotate == 0) {
        rotate = 1;
    }
    
    lastx = -999;
    lasty = -999;
    
    radiusNoise = ofRandom(10);
    spiral = ofRandom(-1,2);
    waitCnt = ofRandom(0, 300);
    step = 0;
    
    col = ofRandom(5);
    a = ofRandom(0, 255);
    waiting = ofRandom(0,80);
    sw = (int)ofRandom(1,8);
    speedX = ofRandom(-2,2);
    speedY = ofRandom(-2,2);

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
    radius += spiral;
    radiusNoise += ofRandom(-0.05, 0.1);
    
    if (flag_r == false) {
        r += 0.1;
        if (r >= 255) {
            flag_r = true;
        }
    }else if(flag_r == true){
        r -= 0.1;
        if (r <= 0) {
            flag_r = false;
        }
    }
    
    
    if (flag_g == false) {
        g += 0.1;
        if (g >= 255) {
            flag_g = true;
        }
    }else if(flag_g == true){
        g -= 0.1;
        if (g <= 0) {
            flag_g = false;
        }
    }
    
    
    if (flag_b == false) {
        b += 0.1;
        if (b >= 255) {
            flag_b = true;
        }
    }else if(flag_b == true){
        b -= 0.1;
        if (b <= 0) {
            flag_b = false;
        }
    }
    
    
    centx += speedX;
    centy += speedY;
    if (centx >= 2117 || centx <= 0) {
        speedX = speedX*-1;
    }
    if (centy >= 950 || centy <= 0) {
        speedY = speedY*-1;
    }
    
}
//--------------------------------------------------------------
void pen::draw(){
    
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    
    if(waiting < 80){
        waiting++;
    }else{
        if(a > 0){ a --; }else{ a = 255;}
    }
    
    if (step < waitCnt) {
        step++;
    }
    else {
        
        float thisRadius = radius + (ofNoise(radiusNoise) * 200) -100;
        
        
        if ((ang > 0 && ang < 360) || (ang < 0 && ang > -360) ) {
            x = centx + (thisRadius * cos(ang*3.141592/180));
            y = centy + (thisRadius * sin(ang*3.141592/180));
            if (lastx > -999) {
                if (col == 0) {
                    ofSetColor(225, 88, 52, a);
                }else if (col == 1){
                    ofSetColor(127, 164, 94, a);
                }else if (col == 2){
                    ofSetColor(239, 243, 193);
                }
                else{
                ofSetColor(r, g, b, a);
                }
                ofSetLineWidth(sw);
                ofLine(x, y, lastx, lasty);
            }
            
            lastx = x;
            lasty = y;
            
        }
        if ((ang > 360) || (ang < -360) ) {
            ang = 0;
        }
        if(radius >= 500){
            spiral = -spiral;
        }else if (radius <= 0){
            spiral = -spiral;
        }
    }
    
}






