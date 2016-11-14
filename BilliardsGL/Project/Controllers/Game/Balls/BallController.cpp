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

bool BallController::isStopping() { return velocity == Vector3D::zero(); }
int BallController::getNum() const { return number; }

void BallController::createBall(ETex texture) {
  SphereRigidObject3D::createSphereModel(texture, Color::one());
}

NS_END
