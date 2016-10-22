//
//  Transform.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/22.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "Transform.hpp"

NS_ENGINE

Transform::Transform(Vector3D pos, Quaternion rot, Vector3D scl)
: position(pos)
, rotation(rot)
, scale(scl)
{ /* do nothing */ }

Transform::~Transform() { /* do nothing */ }

Vector3D Transform::up() const {
  return Vector3D::zero();
}

Vector3D Transform::down() const {
  return Vector3D::zero();
}

Vector3D Transform::left() const {
  return Vector3D::zero();
}

Vector3D Transform::right() const {
  return Vector3D::zero();
}

Vector3D Transform::forward() const {
  return Vector3D::zero();
}

Vector3D Transform::back() const {
  return Vector3D::zero();
}


NS_END
