#include "TestLayer2.h"


//--------------------------------------------------------------------------------------------------------------
void TestLayer2::setup(){
    
    fbo.allocate(1440, 900);
    processFbo.allocate(1440, 900);
    
    image.loadImage("taikan.jpg");
    pixels = image.getPixels();
    
    for (int i=0; i<NUM; i++) {
        
        pos = pens[i].centy * 1440 + pens[i].centx;
        red = pixels[pos *3];
        green = pixels[pos *3 +1];
        blue =  pixels[pos *3 +2];
        pens[i].setR(red);
        pens[i].setG(green);
        pens[i].setB(blue);
        
    }
    alpha = 60;
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
        if (alpha < 60) {
            alpha+=0.1;
        }
    }
    
// phase 1
    if (end_1 == true) {
    if (waiting_2 < 80) {
            waiting_2++;
    }else{
        end_0 = false;
        end_2 = true;
        if (alpha > 0) {
            alpha-=5;
        }
    }
    }

// elase all
    if (end_2 == true) {
        if (waiting_3 < 700) {
            waiting_3++;
        }else{
            end_1 = false;
            end_3 = true;
            if (alpha < 60) {
                alpha+=0.1;
            }
        }
    }

// phase 2
    if (end_3 == true) {
        if (waiting_4 < 80) {
            waiting_4++;
        }else{
            end_2 = false;
            end_4 = true;
            if (alpha > 0) {
                alpha-=5;
            }
        }
    }
    
// reset
    if (end_4 == true) {
        if (waiting_5 < 700) {
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
    processFbo.draw(0, 0);
    fbo.end();
    
    
    
    processFbo.begin();
    for (int i=0; i<NUM; i++) {
        pens[i].draw();
    }
    ofSetColor(190, 150, 80, alpha);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    processFbo.end();
    
    
    
    ofSetHexColor(0xffffff);
    fbo.draw(0,0);

//    cout << "speedX is " << pens[0].speedX << endl;
//    cout << "centx is " << pens[0].centx << endl;
    
}
