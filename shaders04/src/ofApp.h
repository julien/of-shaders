#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

    ofShader shader;
    ofPlanePrimitive plane;
    ofImage img;

public:
    void setup();
    void update();
    void draw();
};
