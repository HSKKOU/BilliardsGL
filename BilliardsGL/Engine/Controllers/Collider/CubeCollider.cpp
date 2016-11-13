//
//  CubeCollider.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/13.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "CubeCollider.hpp"

NS_ENGINE

CubeCollider::CubeCollider(Transform t, Vector3D s)
: Engine::ColliderBase3D(t), size(s)
{ /* do nothing */ }
CubeCollider::CubeCollider(Vector3D s)
: CubeCollider(Transform::identity(), s)
{ /* do nothing */ }
CubeCollider::~CubeCollider() { /* do nothing */ }

Vector3D CubeCollider::getSize() const { return size; }

NS_END
