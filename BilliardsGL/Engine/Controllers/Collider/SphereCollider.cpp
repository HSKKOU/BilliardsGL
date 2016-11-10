//
//  SphereCollider.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/04.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "SphereCollider.hpp"

NS_ENGINE

SphereCollider::SphereCollider(Transform t, GLfloat r) : Engine::ColliderBase3D(t), radius(r*1.1f) { /* do nothing */ }
SphereCollider::SphereCollider(GLfloat r) : SphereCollider(Transform::identity(), r) { /* do nothing */ }
SphereCollider::~SphereCollider() { /* do nothing */ }

GLfloat SphereCollider::getRadius() const { return radius; }

NS_END
