#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(239);
	ofSetWindowTitle("Insta");

	ofNoFill();
	ofSetColor(39);
	ofSetLineWidth(2);
	ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	int rect_size = 144;
	bool flag = true;
	for (int x = rect_size / 2; x <= ofGetWidth() - rect_size / 2; x += rect_size) {

		for (int y = rect_size / 2; y <= ofGetHeight() - rect_size / 2; y += rect_size) {

			ofPushMatrix();
			ofTranslate(x, y);

			for (int size = rect_size; size > 0; size -= rect_size / 6) {

				ofDrawRectangle(ofPoint(), size, size);
				
				int deg = ofMap(ofNoise(x * 0.0005, (y * 0.0005 + ofGetFrameNum() * 0.01) * 1), 0, 1, -120, 120);		
				flag ? ofRotateX(deg) : ofRotateY(deg);
			}

			ofPopMatrix();
			flag = !flag;
		}
	}

}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}