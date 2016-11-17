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
: Engine::SphereRigidObject3D(t, 1.0f, ballRigidBody(), ballSurface(n))
, number(n)
{ /* do nothing */ }
BallController::~BallController() { /* do nothing */ }



bool BallController::isStopping() { return rigidBody.velocity == Vector3D::zero(); }
int BallController::getNum() const { return number; }

RigidBody BallController::ballRigidBody() const { return RigidBody(1.0f, new SphereCollider(1.0f)); }
Surface BallController::ballSurface(int number) const { return Surface(TexUtil::toTex(TexUtil::toInt(ETex::Ball00)+number)); }

NS_END
