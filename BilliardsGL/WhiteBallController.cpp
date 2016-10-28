//
//  WhiteBallController.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/23.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "WhiteBallController.hpp"

NS_GAME

WhiteBallController::WhiteBallController(Transform t) : Game::BallController(t) { /* do nothing */ }
WhiteBallController::~WhiteBallController() { /* do nothing */ }

void WhiteBallController::awake() {
  Sphere* ballModel = (Sphere*)ModelFactory::instantiateModel(ModelType::SPHERE);
  ballModel->loadShaderProgram("LightTest.vert", "LightTest.frag");
  ballModel->setTexture(Tex::Ball00);
  ballModel->setObjectColor(Color::one());
  ballModel->translate(Vector3D(0.0f, 0.0f, 10.0f));
  modelList.emplace_back(ballModel);
}

void WhiteBallController::start() {
  
}

void WhiteBallController::update() {
}

NS_END
