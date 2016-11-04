//
//  BallController.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/23.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "BallController.hpp"

NS_GAME

BallController::BallController(Transform t) : BallController::BallController(t, 0) { /* do nothing */ }
BallController::BallController(Transform t, int n)
: Engine::BaseRigidObject3D(t, 1.0f, SphereCollider(1.0f))
, number(n)
{ /* do nothing */ }
BallController::~BallController() { /* do nothing */ }



void BallController::awake() {
  createBall(TexUtil::toTex(TexUtil::toInt(Tex::Ball00)+number));
}

void BallController::start() {
  
}

void BallController::update() {
  
}



void BallController::createBall(Tex texture) {
  Sphere* ballModel = ModelFactory::createSphereModel(1.0f);
  ballModel->loadShaderProgram("LightTest.vert", "LightTest.frag");
  ballModel->setTexture(texture);
  ballModel->setObjectColor(Color::one());
  ballModel->translate(Vector3D(0.0f, 0.0f, 10.0f));
  modelList.emplace_back(ballModel);
}

NS_END
