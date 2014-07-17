#include "eraser.h"

eraser::eraser(){
    
    centx = ofRandom(1440);
    centy = ofRandom(900);
    radius = 200;
//    rotate = ofRandom(-1.5, 1.5);
//    
//    if (rotate == 0) {
//        rotate = 1;
//    }
//    
//    radiusNoise = ofRandom(10);
//    waitCnt = ofRandom(0, 100);
//    step = 0;
//    
//    sw = ofRandom(5,8);
//    a = ofRandom(0, 255);
//    waiting = ofRandom(0,80);
//    
    speedX = ofRandom(-3,3);
    speedY = ofRandom(-2,2);
    
}

//--------------------------------------------------------------
void eraser::setup(){
    
}

//--------------------------------------------------------------
void eraser::setR(int red){
//    r = red;
}

//--------------------------------------------------------------
void eraser::setG(int green){
//    g = green;
}

//--------------------------------------------------------------
void eraser::setB(int blue){
//    b = blue;
}

//--------------------------------------------------------------
void eraser::setID(int identify){
//    ID = identify;
}

//--------------------------------------------------------------
void eraser::update(){
    
    //  *****   color    *****
    
//    if (flag_c == false) {
//        r += 0.1;
//        g += 0.1;
//        b += 0.1;
//        if (r >= 255 || g >= 255 || b >= 255) {
//            flag_c = true;
//        }
//    }else if(flag_c == true){
//        r -= 0.1;
//        g -= 0.1;
//        b -= 0.1;
//        if (r <= 0 || g <= 0 || b <= 0) {
//            flag_c = false;
//        }
//    }
//    
//    if(waiting < 80){
//        waiting++;
//    }else{
//        if(a > 30){ a --; }else{ a = 255;}
//    }
    
    
    //  *****   radius    *****
    
//    ang += rotate;
//    radiusNoise += ofRandom(-0.05, 0.05);
//    radius += ofRandom(-0.5, 0.5);
//    
//    if (radiusNoise >= 5) {
//        radiusNoise = 0;
//    }
    
    
    //  *****   add velocity to position    *****
    
    centx += speedX;
    centy += speedY;
//    if (centx >= 1440 || centx <= 0) {
//        centx = ofRandom(1440);
//    }
//    if (centy >= 900 || centy <= 0) {
//        centy = ofRandom(900);
//    }
//    
//    float ax = 0.0;
//    float ay = 0.0;
//    int lencon = ofRandom(50)+10;
//    
//    for (int n=0; n<10; n++) {
//        
//        float ddx = this[n].centx-centx;
//        float ddy = this[n].centy-centy;
//        float d = sqrt(ddx*ddx + ddy*ddy);
//        float t = atan2(ddy,ddx);
//        
//        if (this[n].ID > ID) {
//            
//            if (d>lencon) {
//                ax += 10.0 * cos(t);
//                ay += 10.0 * sin(t);
//            }
//        } else {
//            
//            if (d<lencon) {
//                ax += (lencon-d)/10 * cos(t+PI);
//                ay += (lencon-d)/10 * sin(t+PI);
//            }
//        }
//        
//    }
//    
//    
//    if (flag_t == false) {
//        
//        speedX += ax/500; //500
//        speedY += ay/500;
//        if(time > 300){
//            flag_t = true;
//        }
//        
//    }else if (flag_t == true){
//        
//        speedX -= ax/500; //500
//        speedY -= ay/500;
//        if(time > 800){
//            flag_t = false;
//            time = 0;
//        }
//        
//    }
//    
//    speedX *= 0.95;
//    speedY *= 0.95;
//    
//    if (speedX == speedY) {
//        speedX += ofRandom(-0.1, 0.1);
//        speedY += ofRandom(-0.1, 0.1);
//    }
//    
//    if (speedX == 0) {
//        speedX = ofRandom(-0.1, 0.1);
//    }
//    
//    if (speedY == 0) {
//        speedY = ofRandom(-0.1, 0.1);
//    }
    
}
//--------------------------------------------------------------
void eraser::draw(){
    
//    ofFill();
//    ofEnableSmoothing();
//    ofEnableAlphaBlending();
//    
//    
//    float thisRadius = radius + (ofNoise(radiusNoise) * 200) -100;
//    
//    
//    if ((ang >= 0 && ang < 360) || (ang <= 0 && ang > -360) ) {
//        
//        x = centx + (thisRadius * cos(ang*3.1415926/180));
//        y = centy + (thisRadius * sin(ang*3.1415926/180));
//        
        ofSetColor(0,0,0);
        ofCircle(centx, centy, radius);
//
//    }else{
//        
//        reset();
//        
//    }
    
}

//--------------------------------------------------------------
void eraser::reset(){
    
//    centx = ofRandom(1440);
//    centy = ofRandom(900);
//    radius = ofRandom(100);
//    rotate = ofRandom(-5, 5);
//    
//    if (rotate == 0) {
//        rotate = 1;
//    }
//    
//    radiusNoise = ofRandom(10);
//    waitCnt = ofRandom(0, 100);
//    step = 0;
//    
//    a = ofRandom(0, 255);
//    waiting = ofRandom(0,80);
//    
//    speedX = ofRandom(-2,2);
//    speedY = ofRandom(-2,2);
    
}


