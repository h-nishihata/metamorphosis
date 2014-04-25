#ifndef _OF_PEN
#define _OF_PEN

#include "ofMain.h"
extern int r;
extern int g;
extern int b;
class pen{
    
public:
    int x;
    int y;
    int rad;
    int a;
    
    pen();
    void update();
    void draw();
    
};

#endif
