#ifndef _OF_PEN
#define _OF_PEN

#include "ofMain.h"

class pen{
    
public:
// stroke
    float centx;
    float centy;
    float radius;
    float ang;
    float rotate;

    float thisRadius;
    float radiusNoise;
    float spiral;
    float x;
    float y;
    float lastx, lasty;
    
    int waitCnt;
    int step;
    int speedX;
    int speedY;

    
// spots
    float centx_;
    float centy_;
    float radius_;
    float thisRadius_;
    float x_;
    float y_;
    

    float noiseVal;
    float radVariance;
    float rad;

    
//colors
    int sw;
    float r;
    float g;
    float b;
    bool flag_r;
    bool flag_g;
    bool flag_b;
    int col;
    int a;
    int waiting;
    
    
//functions
    pen();
    void setup();
    void update();
    void draw();
    void reset();

    void setR(int red);
    void setG(int green);
    void setB(int blue);
    
};

#endif
