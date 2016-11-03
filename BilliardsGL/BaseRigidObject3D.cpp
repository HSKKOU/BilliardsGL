//
//  BaseRigidObject3D.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/31.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "BaseRigidObject3D.hpp"

NS_ENGINE

BaseRigidObject3D::BaseRigidObject3D(Transform t, ColliderBase3D* col)
: Engine::BaseObject3D(t)
, collider(col)
{ /* do nothing */ }

BaseRigidObject3D::~BaseRigidObject3D() { /* do nothing */ }



ColliderBase3D* BaseRigidObject3D::getCollider3D() const { return collider; }

NS_END
