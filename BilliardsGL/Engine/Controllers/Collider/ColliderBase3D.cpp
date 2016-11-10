//
//  ColliderBase3D.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/31.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "ColliderBase3D.hpp"

NS_ENGINE

ColliderBase3D::ColliderBase3D(Transform local)
: Engine::Base3D(local)
{ /* do nothing */ }
ColliderBase3D::~ColliderBase3D() { /* do nothing */ }

void ColliderBase3D::setParentTransform(Transform* t) { parentTransform = t; }

Vector3D ColliderBase3D::getPosition() const { return parentTransform->position + transform.position; }

NS_END
