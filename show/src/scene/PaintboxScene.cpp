//
//  PaintboxScene.cpp
//  show
//
//  Created by Chris Mullany on 05/09/2015.
//
//

#include "PaintboxScene.h"
using namespace ofxCv;
using namespace cv;

PaintboxScene::PaintboxScene() {
    name = "Paintbox";
}

void PaintboxScene::setup() {
    // subscenes
    subsceneStart = 63;
    subsceneEnd = 66;
    SceneBase::setup();
}

void PaintboxScene::update() {
    if (mode==AppModel::SLAVE) {}
    else if (mode==AppModel::WINDOW) {}
    else if (mode==AppModel::MASTER) {}
    SceneBase::update();
}

void PaintboxScene::draw() {
    if (mode==AppModel::SLAVE) {}
    else if (mode==AppModel::WINDOW) {}
    else if (mode==AppModel::MASTER) {}
    SceneBase::draw();
}

//////////////////////////////////////////////////////////////////////////////////
// public
//////////////////////////////////////////////////////////////////////////////////
void PaintboxScene::play(){
    // start/load/kick things off
    SceneBase::play();
}

void PaintboxScene::stop(){
    // stop/unload/clear things
    SceneBase::stop();
}

void PaintboxScene::setupGui() {
    guiName = "Paintbox";
    panel.setup(guiName, "settings/paintbox.xml");
    // add parameters
    panel.loadFromFile("settings/paintbox.xml");
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