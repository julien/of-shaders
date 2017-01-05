#include "ofApp.h"

void ofApp::setup() {
    shader.load("gl3/vert.glsl", "gl3/frag.glsl");

    img.load("img.jpg");

    plane.set(800, 600, 10, 10);
    plane.mapTexCoords(0, 0, img.getWidth(), img.getHeight());


}

void ofApp::update() {

}

void ofApp::draw() {
    // bind our texture. in the shader this will be
    // tex0 by default, so we can access it there.
    img.getTexture().bind();

    // start shading
    shader.begin();

    // get mouse position relative to center of the screen
    float mousePosition = ofMap(mouseX, 0, ofGetWidth(), 1.0, -1.0, true);

#ifndef TARGET_OPENGLES
    mousePosition *= plane.getWidth();
#endif

    shader.setUniform1f("mouseX", mousePosition);

    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

    plane.draw();

    ofPopMatrix();

    shader.end();

    img.getTexture().unbind();
}

