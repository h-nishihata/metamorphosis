#include "TestLayer2.h"


//--------------------------------------------------------------------------------------------------------------
void TestLayer2::setup(){
    
    fbo.allocate(1440, 900);
    processFbo.allocate(1440, 900);
    
    image.loadImage("taikan.jpg");
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
    alpha = 150;
    end_0 = true;
    end_1 = true;

}
//--------------------------------------------------------------------------------------------------------------
void TestLayer2::update(){

    for (int i=0; i<NUM; i++) {
        pens[i].update();
    }
    
}
//--------------------------------------------------------------------------------------------------------------
void TestLayer2::draw(){
    
    ofTranslate(0, 900);
    ofRotateX(180);

// setting
    if (end_0 == true) {
        waiting_1++;
        if (alpha < 150) {
            alpha+=2;
        }
    }
    
// phase 1
    if (end_1 == true) {
    if (waiting_2 < 200) {
            waiting_2++;
    }else{
        end_0 = false;
        end_2 = true;
        if (alpha > 0) {
            alpha-=2;
        }
    }
    }

// phase 2
    if (end_2 == true) {
        if (waiting_3 < 200) {
            waiting_3++;
        }else{
            end_1 = false;
            end_3 = true;
            if (alpha < 150) {
                alpha+=2;
            }
        }
    }

// phase 3
    if (end_3 == true) {
        if (waiting_4 < 200) {
            waiting_4++;
        }else{
            end_2 = false;
            end_4 = true;
            if (alpha > 0) {
                alpha-=2;
            }
        }
    }
    
// reset
    if (end_4 == true) {
        if (waiting_5 < 200) {
            waiting_5++;
        }else{
            waiting_1 = waiting_2 = waiting_3 = waiting_4 = waiting_5 = 0;
            end_2 = end_3 = end_4 = false;
            end_0 = end_1 = true;
        }
    }
    
    fbo.begin();
    
    ofEnableAlphaBlending();
    ofBackground(0,0,0,0);
//    image.draw(0, 0, 850, 422);
    
    processFbo.draw(0, 0);
    fbo.end();
    
    
    
    processFbo.begin();
    for (int i=0; i<NUM; i++) {
        pens[i].draw();
    }
    ofSetColor(255, 200, 0, alpha);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    processFbo.end();
    
    
    
    ofSetHexColor(0xffffff);
    fbo.draw(0,0);

}
