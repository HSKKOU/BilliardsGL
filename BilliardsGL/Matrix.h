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

#include "glm/glm.hpp"

union Vector3D;
union Vector4D;
union Matrix4D;

union Vector3D {
  struct {
    GLfloat x, y, z;
  };
  GLfloat v[3];
  glm::vec3 vec;
  
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
  
  static Vector3D zero() { return Vector3D(0.0, 0.0, 0.0); }
  static Vector3D one() { return Vector3D(1.0, 1.0, 1.0); }
  
  static Vector3D up() { return Vector3D(0.0, 1.0, 0.0); }
  static Vector3D down() { return Vector3D(0.0, -1.0, 0.0); }
  static Vector3D right() { return Vector3D(1.0, 0.0, 0.0); }
  static Vector3D left() { return Vector3D(-1.0, 0.0, 0.0); }
  static Vector3D forward() { return Vector3D(0.0, 0.0, -1.0); }
  static Vector3D back() { return Vector3D(0.0, 0.0, 1.0); }
  
  void printElem() {
    std::cout << v[0] << ", " << v[1] << ", " << v[2] << std::endl;
  }
};


union Vector4D {
  struct {
    GLfloat x, y, z, w;
  };
  GLfloat v[4];
  glm::vec4 vec;
  
public:
  Vector4D(const GLfloat _x, const GLfloat _y, const GLfloat _z, const GLfloat _w) : x(_x), y(_y), z(_z), w(_w) { /* do nothing */ }
  Vector4D(const Vector3D _v3, const GLfloat _w) : x(_v3.x), y(_v3.y), z(_v3.z), w(_w) { /* do nothing */ }
  
  Vector4D operator+(const GLfloat add) { return Vector4D(x+add, y+add, z+add, w+add); }
  Vector4D operator-(const GLfloat sub) { return Vector4D(x-sub, y-sub, z-sub, w-sub); }
  Vector4D operator*(const GLfloat mul) { return Vector4D(x*mul, y*mul, z*mul, w*mul); }
  Vector4D operator/(const GLfloat div) { return Vector4D(x/div, y/div, z/div, w/div); }
  
  static Vector4D zero() { return Vector4D(0.0, 0.0, 0.0, 0.0); }
  static Vector4D one() { return Vector4D(1.0, 1.0, 1.0, 1.0); }
};


union Matrix4D {
  GLfloat m[4][4];
  glm::mat4 mat;
  
public:
  Matrix4D(GLfloat val) {
    for(int i=0; i<4; i++) {
      for (int j=0; j<4; j++) {
        if (i == j) { m[i][j] = val; }
        else { m[i][j] = 0.0; }
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
  
  static Matrix4D one() { return Matrix4D(1.0); }
  static Matrix4D zero() { return Matrix4D(0.0); }
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
  
  void printElem() {
    for (int i=0; i<4; i++) {
      std::cout << m[i][0] << ", " << m[i][1] << ", " << m[i][2] << ", " << m[i][3] << std::endl;
    }
  }
};



#endif /* Math_h */
