//
//  Base3DController.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/22.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "Base3DController.hpp"

NS_ENGINE

Base3DController::Base3DController() : Engine::Base3D(Transform(Vector3D::zero(), Quaternion::one(), Vector3D::one())) { /* do nothing */ }
Base3DController::Base3DController(Transform t) : Engine::Base3D(t) { /* do nothing */ }
Base3DController::~Base3DController() { /* do nothing */ }

void Base3DController::awake() { /* do nothing */ }
void Base3DController::start() { /* do nothing */ }
void Base3DController::update() { /* do nothing */ }
void Base3DController::lateUpdate() { /* do nothing */ }

NS_END
