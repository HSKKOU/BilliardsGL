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
: Engine::SphereRigidObject3D(t, 1.0f, 1.0f)
, number(n)
{ /* do nothing */ }
BallController::~BallController() { /* do nothing */ }



void BallController::awake() {
  createBall(TexUtil::toTex(TexUtil::toInt(ETex::Ball00)+number));
}



void BallController::createBall(ETex texture) {
  Sphere* ballModel = ModelFactory::createSphereModel(1.0f);
  ballModel->loadShaderProgram("Shaders/Project/test/LightTest.vert", "Shaders/Project/test/LightTest.frag");
  ballModel->setTexture(texture);
  ballModel->setObjectColor(Color::one());
  modelList.emplace_back(ballModel);
}

NS_END
