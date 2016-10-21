//
//  Math.h
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/25.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef Math_h
#define Math_h

#include "GlobalHeader.h"
#include <cmath>

NS_ENGINE

union Vector3D;
union Vector4D;
struct Matrix4D;
union Quaternion;

union Vector3D {
  struct {
    GLfloat x, y, z;
  };
  GLfloat v[3];
  
public:
  Vector3D(const GLfloat _x, const GLfloat _y, const GLfloat _z) : x(_x), y(_y), z(_z) { /* do nothing */ }
  
  Vector3D operator+(const GLfloat add) { return Vector3D(x+add, y+add, z+add); }
  Vector3D operator+(const Vector3D va) { return Vector3D(x+va.x, y+va.y, z+va.z); }
  Vector3D operator-(const GLfloat sub) { return Vector3D(x-sub, y-sub, z-sub); }
  Vector3D operator-(const Vector3D vs) { return Vector3D(x-vs.x, y-vs.y, z-vs.z); }
  Vector3D operator*(const GLfloat mul) { return Vector3D(x*mul, y*mul, z*mul); }
  Vector3D operator/(const GLfloat div) { return Vector3D(x/div, y/div, z/div); }
  
  GLfloat dot(const Vector3D v) { return x*v.x+y*v.y+z*v.z; }
  Vector3D cross(const Vector3D v) { return Vector3D(y*v.z-z*v.y, z*v.x-x*v.z, x*v.y-y*v.x); }
  
  GLfloat length() { return (GLfloat)sqrt(x*x+y*y+z*z); }
  Vector3D normalize() { return this->operator/(length()); }
  
  static Vector3D zero() { return Vector3D(0.0f, 0.0f, 0.0f); }
  static Vector3D one() { return Vector3D(1.0f, 1.0f, 1.0f); }
  
  static Vector3D up() { return Vector3D(0.0f, 1.0f, 0.0f); }
  static Vector3D down() { return Vector3D(0.0f, -1.0f, 0.0f); }
  static Vector3D right() { return Vector3D(1.0f, 0.0f, 0.0f); }
  static Vector3D left() { return Vector3D(-1.0f, 0.0f, 0.0f); }
  static Vector3D forward() { return Vector3D(0.0f, 0.0f, -1.0f); }
  static Vector3D back() { return Vector3D(0.0f, 0.0f, 1.0f); }
  
  void printElem() {
    std::cout << v[0] << ", " << v[1] << ", " << v[2] << std::endl;
  }
};


union Vector4D {
  struct {
    GLfloat x, y, z, w;
  };
  GLfloat v[4];
  
public:
  Vector4D(const GLfloat _x, const GLfloat _y, const GLfloat _z, const GLfloat _w) : x(_x), y(_y), z(_z), w(_w) { /* do nothing */ }
  Vector4D(const Vector3D _v3, const GLfloat _w) : x(_v3.x), y(_v3.y), z(_v3.z), w(_w) { /* do nothing */ }
  
  Vector4D operator+(const GLfloat add) { return Vector4D(x+add, y+add, z+add, w+add); }
  Vector4D operator-(const GLfloat sub) { return Vector4D(x-sub, y-sub, z-sub, w-sub); }
  Vector4D operator*(const GLfloat mul) { return Vector4D(x*mul, y*mul, z*mul, w*mul); }
  Vector4D operator/(const GLfloat div) { return Vector4D(x/div, y/div, z/div, w/div); }
  
  static Vector4D zero() { return Vector4D(0.0f, 0.0f, 0.0f, 0.0f); }
  static Vector4D one() { return Vector4D(1.0f, 1.0f, 1.0f, 1.0f); }
};


union Quaternion {
  struct {
    GLfloat x, y, z, w;
  };
  struct {
    Vector3D vV;
    GLfloat wF;
  };
  GLfloat q[4];
  
public:
  Quaternion() : Quaternion::Quaternion(0.0f, 0.0f, 0.0f, 1.0f) { /* do nothing */ }
  Quaternion(const GLfloat _x, const GLfloat _y, const GLfloat _z, const GLfloat _w) : x(_x), y(_y), z(_z), w(_w) { /* do nothing */ }
  Quaternion(const Vector3D axis, const GLfloat angle)
  : x(axis.x * sinf(angle/2.0f))
  , y(axis.y * sinf(angle/2.0f))
  , z(axis.z * sinf(angle/2.0f))
  , w(cosf(angle/2.0f))
  { /* do nothing */ }
  Quaternion(const GLfloat _x, const GLfloat _y, const GLfloat _z) { /* do nothing */ }
  
  Quaternion operator*(Quaternion _q) {
    Vector3D v = vV * _q.wF + _q.vV * wF + vV.cross(_q.vV);
    return Quaternion(v.x, v.y, v.z, wF*_q.wF - vV.dot(_q.vV) );
  }
  Quaternion& operator*=(Quaternion _q) {
    *this = *this*_q;
    return *this;
  }
  
  static Quaternion one() { return Quaternion(0.0f, 0.0f, 0.0f, 1.0f); }
};


struct Matrix4D {
  GLfloat m[4][4];
  
public:
  Matrix4D() : Matrix4D::Matrix4D(0.0f) { /* do nothing */ }
  Matrix4D(GLfloat val) {
    for(int i=0; i<4; i++) {
      for (int j=0; j<4; j++) {
        if (i == j) { m[i][j] = val; }
        else { m[i][j] = 0.0f; }
      }
    }
  }
  
  Matrix4D operator+(Matrix4D _m) {
    Matrix4D ret = zero();
    for(int i=0; i<4; i++) { for (int j=0; j<4; j++) { ret[i][j] = m[i][j] + _m[i][j]; } }
    return ret;
  }
  Matrix4D operator-(Matrix4D _m) {
    Matrix4D ret = zero();
    for(int i=0; i<4; i++) { for (int j=0; j<4; j++) { ret[i][j] = m[i][j] - _m[i][j]; } }
    return ret;
  }
  Matrix4D operator*(Matrix4D _m) {
    Matrix4D ret = zero();
    for(int i=0; i<4; i++) { for (int j=0; j<4; j++) { for (int k=0; k<4; k++) { ret[i][j] += m[i][k] * _m[k][j]; } } }
    return ret;
  }
  
  GLfloat* operator[](int i) { return m[i]; }
  GLfloat& operator()(int i, int j) { return m[i][j]; }
  
  static Matrix4D one() { return Matrix4D(1.0f); }
  static Matrix4D zero() { return Matrix4D(0.0f); }
  static Matrix4D translate(Matrix4D m, Vector3D v) {
    Matrix4D tm = one();
    tm[3][0] = v.x;
    tm[3][1] = v.y;
    tm[3][2] = v.z;
    return tm * m;
  }
  static Matrix4D rotate(Matrix4D m, Vector3D v, GLfloat t) {
    Matrix4D tm = one();
    GLfloat c = cosf(t);
    GLfloat _c = 1-c;
    GLfloat s = sinf(t);
    tm[0][0] = v.x*v.x*_c + c    ; tm[0][1] = v.x*v.y*_c - v.z*s; tm[0][2] = v.x*v.z*_c + v.y*s;
    tm[1][0] = v.x*v.y*_c + v.z*s; tm[1][1] = v.y*v.y*_c + c    ; tm[1][2] = v.y*v.z*_c - v.x*s;
    tm[2][0] = v.x*v.z*_c - v.y*s; tm[2][1] = v.y*v.z*_c + v.x*s; tm[2][2] = v.z*v.z*_c + c    ;
    return tm * m;
  }
  static Matrix4D rotate(Matrix4D m, Quaternion q) { return fromQuaternion(q) * m; }
  static Matrix4D rotateX(Matrix4D m, GLfloat t) {
    Matrix4D tm = one();
    tm[1][1] = cosf(t);
    tm[1][2] = -sinf(t);
    tm[2][1] = sinf(t);
    tm[2][2] = cosf(t);
    return tm * m;
  }
  static Matrix4D rotateY(Matrix4D m, GLfloat t) {
    Matrix4D tm = one();
    tm[0][0] = cosf(t);
    tm[2][0] = -sinf(t);
    tm[0][2] = sinf(t);
    tm[2][2] = cosf(t);
    return tm * m;
  }
  static Matrix4D rotateZ(Matrix4D m, GLfloat t) {
    Matrix4D tm = one();
    tm[0][0] = cosf(t);
    tm[0][1] = -sinf(t);
    tm[1][0] = sinf(t);
    tm[1][1] = cosf(t);
    return tm * m;
  }
  static Matrix4D scale(Matrix4D m, Vector3D v) {
    Matrix4D tm = one();
    tm[0][0] = v.x;
    tm[1][1] = v.y;
    tm[2][2] = v.z;
    return tm * m;
  }
  
  static Matrix4D fromQuaternion(Quaternion q) {
    Matrix4D m = Matrix4D::one();
    m[0][0] = 1.0f - 2.0f*q.y*q.y - 2.0f*q.z*q.z; m[0][1] = 2.0f*q.x*q.y + 2.0f*q.w*q.z       ; m[0][2] = 2.0f*q.x*q.z - 2.0f*q.w*q.y       ;
    m[1][0] = 2.0f*q.x*q.y - 2.0f*q.w*q.z       ; m[1][1] = 1.0f - 2.0f*q.x*q.x - 2.0f*q.z*q.z; m[1][2] = 2.0f*q.y*q.z + 2.0f*q.w*q.x       ;
    m[2][0] = 2.0f*q.x*q.z + 2.0f*q.w*q.y       ; m[2][1] = 2.0f*q.y*q.z - 2.0f*q.w*q.x       ; m[2][2] = 1.0f - 2.0f*q.x*q.x - 2.0f*q.y*q.y;
    return m;
  }

  void printElem() {
    for (int i=0; i<4; i++) {
      std::cout << m[i][0] << ", " << m[i][1] << ", " << m[i][2] << ", " << m[i][3] << std::endl;
    }
  }
};

NS_END

#endif /* Math_h */
