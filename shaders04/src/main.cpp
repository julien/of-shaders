#include "ofMain.h"
#include "ofApp.h"

int main() {
    ofGLFWWindowSettings settings;

    settings.setGLVersion(3, 2);
    settings.width = 1024;
    settings.height = 768;
    settings.title = " ";
    ofCreateWindow(settings);


    ofRunApp(new ofApp());
}
