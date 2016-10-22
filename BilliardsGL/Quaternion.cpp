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

Quaternion Quaternion::operator*(Quaternion _q) const {
  Vector3D v = vV * _q.wF + _q.vV * wF + vV.cross(_q.vV);
  return Quaternion(v.x, v.y, v.z, wF*_q.wF - vV.dot(_q.vV) );
}
Quaternion& Quaternion::operator*=(Quaternion _q) {
  *this = *this*_q;
  return *this;
}

Vector4D Quaternion::operator*(Vector4D _v4) const {
  return mat4() * _v4;
}
Vector3D Quaternion::operator*(Vector3D _v3) const {
  return (*this * Vector4D(_v3, 1.0f)).vec3();
}

Matrix4D Quaternion::mat4() const {
  Matrix4D m = Matrix4D::one();
  m[0][0] = 1.0f - 2.0f*y*y - 2.0f*z*z; m[0][1] = 2.0f*x*y + 2.0f*w*z       ; m[0][2] = 2.0f*x*z - 2.0f*w*y       ;
  m[1][0] = 2.0f*x*y - 2.0f*w*z       ; m[1][1] = 1.0f - 2.0f*x*x - 2.0f*z*z; m[1][2] = 2.0f*y*z + 2.0f*w*x       ;
  m[2][0] = 2.0f*x*z + 2.0f*w*y       ; m[2][1] = 2.0f*y*z - 2.0f*w*x       ; m[2][2] = 1.0f - 2.0f*x*x - 2.0f*y*y;
  return m;
}

Quaternion Quaternion::one() { return Quaternion(0.0f, 0.0f, 0.0f, 1.0f); }

NS_END
