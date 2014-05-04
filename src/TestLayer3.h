#include "ofMain.h"

#include "ofxLayer.h"
#include "pen.h"
#define OFX_LAYER_DEFINE_LAYER_CLASS(Klass) public: const char* getClassName() const { return #Klass; } \
unsigned int getClassID() const { return ofx::Layer::Type2Int<Klass>::value(); }

#define NUM 100

class TestLayer3 : public ofxLayer::Layer{
public:
    
    OFX_LAYER_DEFINE_LAYER_CLASS(TestLayer3)
    
    void setup();
    void update();
    void draw();
    
    unsigned char* pixels;
    int pos;
    int red;
    int green;
    int blue;
    
    ofFbo fbo;
    ofFbo processFbo;
    ofImage image;
    
    pen pens[NUM];
    
};