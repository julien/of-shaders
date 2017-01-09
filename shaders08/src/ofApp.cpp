#include "ofApp.h"

void ofApp::setup() {
    shader.load("gl3/vert.glsl", "gl3/frag.glsl");

    img.allocate(80, 60, OF_IMAGE_GRAYSCALE);

    plane.set(800, 600, 80, 60);
    plane.mapTexCoordsFromTexture(img.getTexture());
}

void ofApp::update() {

    float scale = ofMap(mouseX, 0, ofGetWidth(), 0, 0.1);
    float vel = ofGetElapsedTimef();

    ofPixels &pixels = img.getPixels();
    int w = img.getWidth();
    int h = img.getHeight();

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int i = y * w + x;
            float val = ofNoise(x * scale, y * scale, vel);
            pixels[i] = 255 * val;
        }
    }
    img.update();
}

void ofApp::draw() {

    // bind our texture, it will be available as tex0 in our shader
    img.getTexture().bind();

    shader.begin();

    ofPushMatrix();

    // translate plane into center screen
    float tx = ofGetWidth() / 2;
    float ty = ofGetHeight() / 2;
    ofTranslate(tx, ty);

    // the mouse/touch Y position changes the rotation of the plane
    float percentY = mouseY / (float) ofGetHeight();
    float rotation = ofMap(percentY, 0, 1, -60, 60, true) + 60;
    ofRotate(rotation, 1, 0, 0);

    plane.drawWireframe();

    ofPopMatrix();

    shader.end();

    ofSetColor(ofColor::white);
    img.draw(0, 0);
}

