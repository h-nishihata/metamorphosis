#include "TestLayer3.h"

//--------------------------------------------------------------------------------------------------------------
void TestLayer3::setup(){
    
    fbo.allocate(1440, 713);
    processFbo.allocate(1440, 713);
    
    image.loadImage("collection_12.jpg");
    pixels = image.getPixels();
    
    for (int i=0; i<NUM; i++) {
        
        pos = pens[i].centy * image.width + pens[i].centx;
        red = pixels[pos *3];
        green = pixels[pos *3 +1];
        blue =  pixels[pos *3 +2];
        pens[i].setR(red);
        pens[i].setG(green);
        pens[i].setB(blue);
        
    }
    
    ofSetFrameRate(10);
    
}
//--------------------------------------------------------------------------------------------------------------
void TestLayer3::update(){
    
    for (int i=0; i<NUM; i++) {
        pens[i].update();
    }
    
}
//--------------------------------------------------------------------------------------------------------------
void TestLayer3::draw(){
    
    fbo.begin();
    
    ofEnableAlphaBlending();
    ofBackground(0,0,0,0);
    image.draw(0, 0, 850, 422);
    
    processFbo.draw(0, 0);
    fbo.end();
    
    
    
    processFbo.begin();
    for (int i=0; i<NUM; i++) {
        pens[i].draw();
    }
    processFbo.end();
    
    
    
    ofSetHexColor(0xffffff);
    fbo.draw(0,0);
    
}
