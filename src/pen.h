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
    float x;
    float y;
    
    int waitCnt;
    int step;
    int speedX;
    int speedY;
    int time;
    bool flag_t;
    
    
    //colors
    bool setEraser;
    float r;
    float g;
    float b;
    bool flag_c;
    int col;
    float a;
    int waiting;
    int ID;
    
    
    //functions
    pen();
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
