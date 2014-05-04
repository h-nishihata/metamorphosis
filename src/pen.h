#ifndef _OF_PEN
#define _OF_PEN

#include "ofMain.h"

class pen{
    
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

    int r;
    int g;
    int b;
    float col;
    bool flag;
    int a;
    int waiting;
    int sw;
    int speedX;
    int speedY;
    
    pen();
    void setup();
    void update();
    void draw();
    void setR(int red);
    void setG(int green);
    void setB(int blue);
    
};

#endif
