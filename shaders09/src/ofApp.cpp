#include "ofApp.h"

void ofApp::setup() {
    shaderBlurX.load("gl3/blurx_vert.glsl", "gl3/blurx_frag.glsl");
    shaderBlurY.load("gl3/blury_vert.glsl", "gl3/blury_frag.glsl");

    img.load("img.jpg");
    fboPass1.allocate(img.getWidth(), img.getHeight());
    fboPass2.allocate(img.getWidth(), img.getHeight());
}

void ofApp::update() {
}

void ofApp::draw() {
    float blur = ofMap(mouseX, 0, ofGetWidth(), 0, 10, true);

    // first pass
    fboPass1.begin();

    shaderBlurX.begin();
    shaderBlurX.setUniform1f("blurAmnt", blur);

    img.draw(0, 0);

    shaderBlurX.end();

    fboPass1.end();

    // second pass
    fboPass2.begin();

    shaderBlurY.begin();
    shaderBlurY.setUniform1f("blurAmnt", blur);

    fboPass1.draw(0, 0);

    shaderBlurY.end();

    fboPass2.end();

    // set background color and draw final fbo
    ofSetColor(ofColor::white);
    fboPass2.draw(0, 0);
}

