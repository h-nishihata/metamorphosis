#ifndef _OF_eraser
#define _OF_eraser

#include "ofMain.h"

class eraser{
    
public:
    
    // stroke
    float centx;
    float centy;
    float radius;
    float ang;
    float rotate;
    
    float thisRadius;
    float radiusNoise;
    float x;
    float y;
    
    int waitCnt;
    int step;
    int speedX;
    int speedY;
    int time;
    bool flag_t;
    
    
    //colors
    int sw;
    float r;
    float g;
    float b;
    bool flag_c;
    int col;
    int a;
    int waiting;
    int ID;
    
    
    //functions
    eraser();
    void setup();
    void update();
    void draw();
    void reset();
    
    void setR(int red);
    void setG(int green);
    void setB(int blue);
    void setID(int ID);
    
};

#endif
