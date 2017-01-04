#include "ofApp.h"

void ofApp::setup() {
    shader.load("gl3/vert.glsl", "gl3/frag.glsl");
}

void ofApp::update() {

}

void ofApp::draw() {
    ofSetColor(255);
    shader.begin();
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    shader.end();
}

