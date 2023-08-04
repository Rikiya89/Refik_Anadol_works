#pragma once

#include "ofMain.h"

class Particle {
public:
    ofVec3f position;
    ofVec3f velocity;
    ofVec3f noiseSeed;
    ofColor color;

    Particle() {
        position = ofVec3f(ofRandom(-500, 500), ofRandom(-500, 500), ofRandom(-500, 500));
        noiseSeed = ofVec3f(ofRandom(0, 1000), ofRandom(0, 1000), ofRandom(0, 1000));
        color = ofColor::fromHsb(ofRandom(255), 255, 255);
    }

    void update() {
        velocity = ofVec3f(
            ofSignedNoise(noiseSeed.x, ofGetElapsedTimef()) * 10.0,
            ofSignedNoise(noiseSeed.y, ofGetElapsedTimef()) * 10.0,
            ofSignedNoise(noiseSeed.z, ofGetElapsedTimef()) * 10.0
        );
        position += velocity;
        if (position.distance(ofVec3f(0, 0, 0)) > 500) {
            position.normalize() *= 500;
        }
    }

    void draw() {
        ofSetColor(color);
        ofDrawSphere(position, 2);
    }
};

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

private:
    ofEasyCam cam;
    std::vector<Particle> particles;
};
