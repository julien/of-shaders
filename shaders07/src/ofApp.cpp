#include "ofApp.h"

void ofApp::setup() {
    shader.load("gl3/vert.glsl", "gl3/frag.glsl");

    background.load("A.jpg");
    foreground.load("B.jpg");
    brush.load("brush.png");

    int width = background.getWidth();
    int height = background.getHeight();

    fboMask.allocate(width, height);
    fbo.allocate(width, height);

    // clear fbo's
    // othewise they will hold "junk" from the memory

    fboMask.begin();
    ofClear(0, 0, 0, 255);
    fboMask.end();

    fbo.begin();
    ofClear(0, 0, 0, 255);
    fbo.end();

    brushDown = false;
}

void ofApp::update() {
}

void ofApp::draw() {

    ofSetColor(255);

    // the alpha mask which we draw into
    if (brushDown) {
        fboMask.begin();

        int size = 50;
        int x = mouseX - size * 0.5;
        int y = mouseY - size * 0.5;
        brush.draw(x, y, size, size);

        fboMask.end();
    }

    fbo.begin();
    // cleaning everything with alpha mask on 0
    // to make it transparent by default
    ofClear(0, 0, 0, 0);

    shader.begin();
    // pass the fbo to the shader
    shader.setUniformTexture("maskTex", fboMask.getTexture(), 1);

    background.draw(0, 0);
    shader.end();
    fbo.end();

    // draw background image
    foreground.draw(0, 0);

    // draw masked fbo on top
    fbo.draw(0, 0);

    ofDrawBitmapString("Drag the mouse to draw", 15, 15);
    ofDrawBitmapString("Press spacebar to clear", 15, 30);
}

void ofApp::keyPressed(int key) {
    if (key == ' ') {
        fboMask.begin();
        ofClear(0, 0, 0, 255);
        fbo.end();
    }
}

void ofApp::mousePressed(int x, int y, int button) {
    brushDown = true;
}

void ofApp::mouseReleased(int x, int y, int button) {
    brushDown = false;
}

