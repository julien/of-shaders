#include "ofApp.h"

void ofApp::setup() {
    shader.load("gl3/vert.glsl", "gl3/frag.glsl");

    float planeScale = 0.75;
    int planeWidth = ofGetWidth() * planeScale;
    int planeHeight = ofGetHeight() * planeScale;
    int planeGridSize = 20;
    int planeColumns = planeWidth / planeGridSize;
    int planeRows = planeHeight / planeGridSize;

    plane.set(planeWidth, planeHeight, planeColumns, planeRows, OF_PRIMITIVE_TRIANGLES);
}

void ofApp::update() {

}

void ofApp::draw() {

    float percentX = mouseX / (float) ofGetWidth();
    percentX = ofClamp(percentX, 0, 1);

    // the mouse/touch X position changes the color of the plane.
    ofColor colorLeft = ofColor::magenta;
    ofColor colorRight = ofColor::cyan;
    ofColor colorMix = colorLeft.getLerped(colorRight, percentX);
    ofSetColor(colorMix);

    shader.begin();

    shader.setUniform1f("time", ofGetElapsedTimef());

    // translate plance to screen center
    float tx = ofGetWidth() / 2;
    float ty = ofGetHeight() / 2;
    ofTranslate(tx, ty);

    // the mouse/touch Y position changes the rotation of the plane.
    float percentY = mouseY / (float) ofGetHeight();
    float rotation = ofMap(percentY, 0, 1, -60, 60, true) + 60;
    ofRotate(rotation, 1, 0, 0);

    plane.drawWireframe();
    shader.end();
}

