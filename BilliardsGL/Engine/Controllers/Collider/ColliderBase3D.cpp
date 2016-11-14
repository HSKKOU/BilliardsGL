//
//  ColliderBase3D.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/31.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "ColliderBase3D.hpp"

NS_ENGINE

ColliderBase3D::ColliderBase3D(Transform local, COL_MASK cType)
: Engine::Base3D(local)
, colliderType(cType)
{ /* do nothing */ }
ColliderBase3D::~ColliderBase3D() { /* do nothing */ }

Vector3D ColliderBase3D::getPosition() const { return transform.position; }

COL_MASK ColliderBase3D::getColliderType() const { return colliderType; }

NS_END
