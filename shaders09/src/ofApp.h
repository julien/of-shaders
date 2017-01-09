#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

    ofShader shaderBlurX;
    ofShader shaderBlurY;

    ofFbo fboPass1;
    ofFbo fboPass2;

    ofImage img;

public:
    void setup();
    void update();
    void draw();
};
