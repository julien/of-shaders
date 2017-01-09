#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

    ofShader shader;

    ofImage background;
    ofImage foreground;
    ofImage brush;

    ofFbo fbo;
    ofFbo fboMask;

    bool brushDown;

public:
    void setup();
    void update();
    void draw();

	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
};
