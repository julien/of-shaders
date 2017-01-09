#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

    ofShader shader;

    ofImage img;
    ofImage imgMask;
    ofVideoPlayer movie;

    ofFbo fbo;
    ofFbo fboMask;

public:
    void setup();
    void update();
    void draw();
};
