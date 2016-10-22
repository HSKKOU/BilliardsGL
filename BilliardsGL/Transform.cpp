//
//  Transform.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/22.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "Transform.hpp"

NS_ENGINE

Transform::Transform(Transform const &t) : Transform::Transform(t.position, t.rotation, t.scale) { /* do nothing */ }
Transform::Transform(Vector3D pos, Quaternion rot, Vector3D scl)
: position(pos)
, rotation(rot)
, scale(scl)
{ /* do nothing */ }

Transform::~Transform() { /* do nothing */ }

Vector3D Transform::up() const { return rotation * Vector3D::up(); }
Vector3D Transform::down() const { return rotation * Vector3D::down(); }
Vector3D Transform::left() const { return rotation * Vector3D::left(); }
Vector3D Transform::right() const { return rotation * Vector3D::right(); }
Vector3D Transform::forward() const { return rotation * Vector3D::forward(); }
Vector3D Transform::back() const { return rotation * Vector3D::back(); }

void Transform::lookAt(Vector3D target, Vector3D upDir) {
  // TODO : impl lookAt
}

NS_END
