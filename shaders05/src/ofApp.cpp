#include "ofApp.h"

void ofApp::setup() {
    shader.load("gl3/vert.glsl", "gl3/frag.glsl");

    img.load("img.jpg");
    imgMask.load("img_mask.png");

    // plane.set(800, 600, 10, 10);
    // plane.mapTexCoords(0, 0, img.getWidth(), img.getHeight());

}

void ofApp::update() {

}

void ofApp::draw() {
    ofDrawRectangle(0, 0, img.getWidth(), img.getHeight());

    shader.begin();
    shader.setUniform1f("time", ofGetElapsedTimef());

    shader.setUniformTexture("imageMask", imgMask.getTexture(), 1);
    img.draw(0, 0);

    shader.end();
}

