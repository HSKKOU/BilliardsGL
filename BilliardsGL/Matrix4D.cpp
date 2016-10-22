//
//  Matrix4D.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/22.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "Matrix4D.hpp"

NS_ENGINE

Matrix4D::Matrix4D() : Matrix4D::Matrix4D(0.0f) { /* do nothing */ }
Matrix4D::Matrix4D(GLfloat val) {
  for(int i=0; i<4; i++) {
    for (int j=0; j<4; j++) {
      if (i == j) { m[i][j] = val; }
      else { m[i][j] = 0.0f; }
    }
  }
}

Matrix4D Matrix4D::operator+(Matrix4D _m) const {
  Matrix4D ret = zero();
  for(int i=0; i<4; i++) { ret.v[i] = v[i] + _m.v[i]; }
  return ret;
}
Matrix4D Matrix4D::operator-(Matrix4D _m) const {
  Matrix4D ret = zero();
  for(int i=0; i<4; i++) { ret.v[i] = v[i] - _m.v[i]; }
  return ret;
}
Matrix4D Matrix4D::operator*(Matrix4D _m) const {
  Matrix4D ret = zero();
  Matrix4D _mInv = _m.inverse();
  for(int i=0; i<4; i++) { for (int j=0; j<4; j++) { ret[i][j] += v[i].dot(_mInv.v[j]); } }
  return ret;
}
Vector4D Matrix4D::operator*(Vector4D _v) const {
  Vector4D ret = Vector4D::zero();
  for(int i=0; i<4; i++) { ret.v[i] = v[i].dot(_v); }
  return ret;
}

Vector4D& Matrix4D::operator[](int i) { return v[i]; }

Matrix4D Matrix4D::inverse() const {
  Matrix4D ret = zero();
  for(int i=0; i<4; i++) { for (int j=0; j<4; j++) { ret[i][j] = m[j][i]; } }
  return ret;
}

Matrix4D Matrix4D::one() { return Matrix4D(1.0f); }
Matrix4D Matrix4D::zero() { return Matrix4D(0.0f); }
Matrix4D Matrix4D::translate(Matrix4D m, Vector3D v) {
  Matrix4D tm = one();
  tm[3][0] = v.x;
  tm[3][1] = v.y;
  tm[3][2] = v.z;
  return tm * m;
}
Matrix4D Matrix4D::rotate(Matrix4D m, Vector3D v, GLfloat t) {
  Matrix4D tm = one();
  GLfloat c = cosf(t);
  GLfloat _c = 1-c;
  GLfloat s = sinf(t);
  tm[0][0] = v.x*v.x*_c + c    ; tm[0][1] = v.x*v.y*_c - v.z*s; tm[0][2] = v.x*v.z*_c + v.y*s;
  tm[1][0] = v.x*v.y*_c + v.z*s; tm[1][1] = v.y*v.y*_c + c    ; tm[1][2] = v.y*v.z*_c - v.x*s;
  tm[2][0] = v.x*v.z*_c - v.y*s; tm[2][1] = v.y*v.z*_c + v.x*s; tm[2][2] = v.z*v.z*_c + c    ;
  return tm * m;
}
Matrix4D Matrix4D::rotate(Matrix4D m, Quaternion q) { return fromQuaternion(q) * m; }
Matrix4D Matrix4D::rotateX(Matrix4D m, GLfloat t) {
  Matrix4D tm = one();
  tm[1][1] = cosf(t);
  tm[1][2] = -sinf(t);
  tm[2][1] = sinf(t);
  tm[2][2] = cosf(t);
  return tm * m;
}
Matrix4D Matrix4D::rotateY(Matrix4D m, GLfloat t) {
  Matrix4D tm = one();
  tm[0][0] = cosf(t);
  tm[2][0] = -sinf(t);
  tm[0][2] = sinf(t);
  tm[2][2] = cosf(t);
  return tm * m;
}
Matrix4D Matrix4D::rotateZ(Matrix4D m, GLfloat t) {
  Matrix4D tm = one();
  tm[0][0] = cosf(t);
  tm[0][1] = -sinf(t);
  tm[1][0] = sinf(t);
  tm[1][1] = cosf(t);
  return tm * m;
}
Matrix4D Matrix4D::scale(Matrix4D m, Vector3D v) {
  Matrix4D tm = one();
  tm[0][0] = v.x;
  tm[1][1] = v.y;
  tm[2][2] = v.z;
  return tm * m;
}

Matrix4D Matrix4D::fromQuaternion(Quaternion q) {
  Matrix4D m = Matrix4D::one();
  m[0][0] = 1.0f - 2.0f*q.y*q.y - 2.0f*q.z*q.z; m[0][1] = 2.0f*q.x*q.y + 2.0f*q.w*q.z       ; m[0][2] = 2.0f*q.x*q.z - 2.0f*q.w*q.y       ;
  m[1][0] = 2.0f*q.x*q.y - 2.0f*q.w*q.z       ; m[1][1] = 1.0f - 2.0f*q.x*q.x - 2.0f*q.z*q.z; m[1][2] = 2.0f*q.y*q.z + 2.0f*q.w*q.x       ;
  m[2][0] = 2.0f*q.x*q.z + 2.0f*q.w*q.y       ; m[2][1] = 2.0f*q.y*q.z - 2.0f*q.w*q.x       ; m[2][2] = 1.0f - 2.0f*q.x*q.x - 2.0f*q.y*q.y;
  return m;
}

void Matrix4D::printElem() const {
  for (int i=0; i<4; i++) {
    std::cout << m[i][0] << ", " << m[i][1] << ", " << m[i][2] << ", " << m[i][3] << std::endl;
  }
}

NS_END
