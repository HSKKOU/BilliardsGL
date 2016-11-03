//
//  ColliderBase3D.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/31.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "ColliderBase3D.hpp"

NS_ENGINE

ColliderBase3D::ColliderBase3D() { /* do nothing */ }
ColliderBase3D::~ColliderBase3D() { /* do nothing */ }

bool ColliderBase3D::isCollideWith(BaseObject3D* object) {
  return false;
}

NS_END
