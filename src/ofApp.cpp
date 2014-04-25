#include "ofApp.h"
int r;
int g;
int b;
int x = 0;
//--------------------------------------------------------------
void ofApp::setup(){
    
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RG8);
    processFbo.allocate(ofGetWidth(), ofGetHeight());
    image.loadImage("collection_12.jpg");
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i=0; i<NUM; i++) {
        pens[i].update();
    }
    x++;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    fbo.begin();
    image.draw(0, 0);
    //    ofBackground(0);
    unsigned char* pixels = image.getPixels();
    int pos = 400*image.width+400;
    r = pixels[pos*3];
    g = pixels[pos*3+1];
    b = pixels[pos*3+2];
    processFbo.draw(0, 0);
    
    
    fbo.end();
    
    processFbo.begin();
//    ofSetColor(r,g,b);
//    ofEllipse(x, 50, 100, 100);
    for (int i=0; i<NUM; i++) {
        pens[i].draw();
    }
    processFbo.end();
    
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