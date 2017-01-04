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

    shader.begin();

    // center screen
    float cx = ofGetWidth() / 2.0;
    float cy = ofGetHeight() / 2.0;

    // the plane is positioned at the center of the screen
    // so we need to apply the same offset to the mouse coordinates
    // before passing into the shader
    float mx = mouseX - cx;
    float my = mouseY - cy;

    shader.setUniform1f("mouseRange", 150);

    shader.setUniform2f("mousePos", mx, my);


    float percentX = mouseX / (float) ofGetWidth();
    percentX = ofClamp(percentX, 0, 1);

    ofFloatColor colorLeft = ofColor::magenta;
    ofFloatColor colorRight = ofColor::blue;
    ofFloatColor colorMix = colorLeft.getLerped(colorRight, percentX);

    float mouseColor[4] = {colorMix.r, colorMix.g, colorMix.b, colorMix.a};

    shader.setUniform4fv("mouseColor", &mouseColor[0]);

    ofTranslate(cx, cy);
    plane.drawWireframe();
    shader.end();
}

