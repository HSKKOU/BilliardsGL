//
//  BallController.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/23.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "BallController.hpp"

NS_GAME

BallController::BallController(Transform t) : Engine::BaseObject3D(t), number(0) { /* do nothing */ }
BallController::BallController(Transform t, int n) : Engine::BaseObject3D(t), number(n) { /* do nothing */ }
BallController::~BallController() { /* do nothing */ }

void BallController::awake() {
  Sphere* ballModel = (Sphere*)ModelFactory::instantiateModel(ModelType::SPHERE);
  ballModel->loadShaderProgram("LightTest.vert", "LightTest.frag");
  ballModel->setTexture(TexUtil::toTex(TexUtil::toInt(Tex::Ball00)+number));
  ballModel->setObjectColor(Color::one());
  ballModel->translate(Vector3D(0.0f, 0.0f, 10.0f));
  modelList.emplace_back(ballModel);
}

void BallController::start() {
  
}

void BallController::update() {
  
}

NS_END
