//
//  Quaternion.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/22.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "Quaternion.hpp"

NS_ENGINE

Quaternion::Quaternion() : Quaternion::Quaternion(0.0f, 0.0f, 0.0f, 1.0f) { /* do nothing */ }
Quaternion::Quaternion(const GLfloat _x, const GLfloat _y, const GLfloat _z, const GLfloat _w)
: x(_x), y(_y), z(_z), w(_w)
{ /* do nothing */ }
Quaternion::Quaternion(const Vector3D axis, const GLfloat angle)
: x(axis.x * sinf(angle/2.0f))
, y(axis.y * sinf(angle/2.0f))
, z(axis.z * sinf(angle/2.0f))
, w(cosf(angle/2.0f))
{ /* do nothing */ }
Quaternion::Quaternion(const GLfloat _x, const GLfloat _y, const GLfloat _z) { /* do nothing */ }

Quaternion Quaternion::operator*(Quaternion _q) {
  Vector3D v = vV * _q.wF + _q.vV * wF + vV.cross(_q.vV);
  return Quaternion(v.x, v.y, v.z, wF*_q.wF - vV.dot(_q.vV) );
}
Quaternion& Quaternion::operator*=(Quaternion _q) {
  *this = *this*_q;
  return *this;
}

Quaternion Quaternion::one() { return Quaternion(0.0f, 0.0f, 0.0f, 1.0f); }

NS_END
