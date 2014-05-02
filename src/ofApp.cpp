#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    fbo.allocate(1440, 713, GL_RGB);
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

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i=0; i<NUM; i++) {
        pens[i].update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
   
    fbo.begin();
            image.draw(0, 0, 850, 422);
            //    ofEnableAlphaBlending();
            //    ofBackground(0,0,0,0);
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

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
