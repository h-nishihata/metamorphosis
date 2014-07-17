#include "TestLayer3.h"

//--------------------------------------------------------------------------------------------------------------
void TestLayer3::setup(){
    
    img.loadImage("tohaku.jpg");
    x = -200;
    y = 0;
    speedX = 0.1;
    speedY = 0.1;
//    r = 240;
//    g = 229;
//    b = 171;
    
}
//--------------------------------------------------------------------------------------------------------------
void TestLayer3::update(){
    
    x += speedX;
    y += speedY;
    
    if (x >= 0 || x <= -550) {
        speedX = speedX*-1;
    }
    if (y >= 0 || y <= -50) {
        speedY = speedY*-1;
    }
    
    /*
     if (flag_r == false) {
     r +=0.1;
     if (r >= 200) {
     flag_r = true;
     }
     }else if(flag_r == true){
     r -=0.1;
     if (r <= 80) {
     flag_r = false;
     }
     }
     
     if (flag_g == false) {
     g +=0.1;
     if (g >= 200) {
     flag_g = true;
     }
     }else if(flag_g == true){
     g -=0.1;
     if (g <= 80) {
     flag_g = false;
     }
     }
     
     if (flag_b == false) {
     b +=0.1;
     if (b >= 200) {
     flag_b = true;
     }
     }else if(flag_b == true){
     b -=0.1;
     if (b <= 80) {
     flag_b = false;
     }
     }
     */
}
//--------------------------------------------------------------------------------------------------------------
void TestLayer3::draw(){
    
    
    ofEnableAlphaBlending();
    ofBackground(255,255,255,0);
    
//    ofSetColor(245,229,171);
    img.draw(x, y, 2832 * 1.29, 1200);
    
}
