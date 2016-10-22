//
//  BaseObject3D.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/22.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "BaseObject3D.hpp"

NS_ENGINE

BaseObject3D::BaseObject3D() : Engine::Base3D(Transform(Vector3D::zero(), Quaternion::one(), Vector3D::one())) { /* do nothing */ }
BaseObject3D::BaseObject3D(Transform t) : Engine::Base3D(t) { /* do nothing */ }
BaseObject3D::~BaseObject3D() { /* do nothing */ }

void BaseObject3D::awake() { /* do nothing */ }
void BaseObject3D::start() { /* do nothing */ }
void BaseObject3D::update() { /* do nothing */ }
void BaseObject3D::lateUpdate() { /* do nothing */ }

NS_END
