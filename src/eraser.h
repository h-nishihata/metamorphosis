#ifndef _OF_ERASER
#define _OF_ERASER

#include "ofMain.h"

class eraser{
    
public:
    
    int centx, centy;
    int radius;
    int ang;
    int rotate;
    float x, y;
    int lastx, lasty;
    
    float radiusNoise;
    float spiral;
    int waitCnt;
    int step;
    
    //    float r;
    //    float g;
    //    float b;
    //    float col;
    //    bool flag_r;
    //    bool flag_g;
    //    bool flag_b;
    int a;
    int waiting;
    int sw;
    int speedX;
    int speedY;
    
    eraser();
    void setup();
    void update();
    void draw();
    //    void setR(int red);
    //    void setG(int green);
    //    void setB(int blue);
    
};

#endif
