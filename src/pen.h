#ifndef _OF_PEN
#define _OF_PEN

#include "ofMain.h"

class pen{
    
public:
    int centx, centy;
    int radius;
    int ang;
    int rotate;
    int radiusNoise;
    int spiral;
    float x, y;
    int lastx, lasty;
    int waitCnt;
    int step;
    
    //    int pos;
    int r;
    int g;
    int b;
    
    pen();
    //    pen(int centX, int centY);
    void setup();
    void update();
    void draw();
    void setR(int red);
    void setG(int green);
    void setB(int blue);
};

#endif
