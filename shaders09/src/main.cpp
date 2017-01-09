#include "ofMain.h"
#include "ofApp.h"

int main() {
    ofGLFWWindowSettings settings;

    settings.setGLVersion(3, 2);
    settings.width = 800;
    settings.height = 600;
    settings.title = " ";
    ofCreateWindow(settings);


    ofRunApp(new ofApp());
}
