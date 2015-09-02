//
//  VisionManager.h
//  show
//
//  Created by Chris Mullany on 02/09/2015.
//
//

#pragma once
#include "ofMain.h"
#include "ofxCv.h"
#include "IPCamInput.h"
#include "VideoInput.h"

// manages vision-based inputs: IP camera, video file, image file, etc
// applies distortion coorection to active input
// exposes the output image to the rest of the app
//
class VisionManager {
public:
    VisionManager();
    
	void setup();
	void update();
	void draw();
	void exit();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

protected:  
private:
    
    IPCamInput ipcam;
    VideoInput video;
    vector<IVisionInput*> inputs;
    int inputIndex;
    IVisionInput* input;
    
    ofxCv::Calibration calibration;
    ofImage inputImage, outputImage;
    ofPixels previous;
    ofPixels diff;
    float diffMean;
    float lastTime;
    
    bool isFirstImage;
    
};