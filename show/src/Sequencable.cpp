//
//  Sequencable.cpp
//  show
//
//  Created by Chris Mullany on 04/09/2015.
//
//

#include "Sequencable.h"

void Sequencable::update() {
    progress = tween.update();
    if (tween.isCompleted()) {
        if (state == INTRO) setState(INTERACTIVE);
        else if (state == INTERACTIVE && timeHold > 0) setState(OUTRO);
        else  if (state == OUTRO) {
            if (loop) {
                loopNum++;
                setState(INTRO);
            }
            else setState(INACTIVE);
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////
// public
//////////////////////////////////////////////////////////////////////////////////
void Sequencable::setState(State state, float delay) {
    this->state = state;
    ofNotifyEvent(stateChangeEvent, state, this);
    if (state == INTRO) {
        tween.setParameters(easinglinear, ofxTween::easeOut, 0, 1, timeIn*1000, delay * 1000);
    }
    else if (state == INTERACTIVE && timeHold > 0) {
        tween.setParameters(easinglinear, ofxTween::easeOut, 0, 1, timeHold*1000, delay * 1000);
    }
    else if (state == OUTRO) {
        tween.setParameters(easinglinear, ofxTween::easeOut, 0, 1, timeOut*1000, delay * 1000);
    }
    tween.start();
    progress = 0;
}

void Sequencable::play() {
    if (timeIn > 0) setState(INTRO);
    else setState(INTERACTIVE);
    loopNum = 1;
}
void Sequencable::stop() {
    loop = false;
    if (timeOut > 0) setState(OUTRO);
    else setState(INACTIVE);
}

//////////////////////////////////////////////////////////////////////////////////
// protected
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
// private
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
// custom event handlers
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
// oF event handlers
//////////////////////////////////////////////////////////////////////////////////

