#include "ofApp.h"

void ofApp::setup() {
    shader.load("gl3/vert.glsl", "gl3/frag.glsl");

    int width = 320;
    int height = 240;

    movie.load("movie.mov");
    movie.play();

    img.load("img.jpg");
    imgMask.load("mask.jpg");

    fbo.allocate(width, height);
    fboMask.allocate(width, height);

}

void ofApp::update() {
    movie.update();
}

void ofApp::draw() {

    // draw to mask fbo
    fboMask.begin();

    ofClear(255, 0, 0, 255);

    float imgMaskX = mouseX / (float) ofGetWidth();
    imgMaskX = ofClamp(imgMaskX, 0, 1);
    imgMaskX = -(imgMask.getWidth() - fboMask.getWidth()) * imgMaskX;
    imgMask.draw(imgMaskX, 0);

    fboMask.end();

    // draw to final fbo
    fbo.begin();

    ofClear(0, 0, 0, 255);

    shader.begin();
    shader.setUniformTexture("tex0", img, 1);
    shader.setUniformTexture("tex1", movie.getTexture(), 2);
    shader.setUniformTexture("imageMask", fboMask.getTexture(), 3);

    // draw every frame to the mask fbo
    fboMask.draw(0, 0);

    shader.end();
    fbo.end();


    ofSetColor(255);

    img.draw(5, 5, 320, 240);
    movie.draw(325, 5, 320, 240);
    fboMask.draw(5, 245, 320, 240);
    fbo.draw(325, 245, 320, 240);
}


