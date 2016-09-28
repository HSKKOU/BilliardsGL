//
//  Vector.h
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/25.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef Vector_h
#define Vector_h

#include "GlobalHeader.h"

#include "glm/glm.hpp"

union Vector3D;
union Vector4D;

union Vector3D {
  struct {
    GLfloat x, y, z;
  };
  GLfloat v[3];
  
public:
  Vector3D(GLfloat _x, GLfloat _y, GLfloat _z) : x(_x), y(_y), z(_z) { /* do nothing */ }
  
  Vector3D operator+(GLfloat add) { return Vector3D(x+add, y+add, z+add); }
  Vector3D operator-(GLfloat sub) { return Vector3D(x-sub, y-sub, z-sub); }
  Vector3D operator*(GLfloat mul) { return Vector3D(x*mul, y*mul, z*mul); }
  Vector3D operator/(GLfloat div) { return Vector3D(x/div, y/div, z/div); }
  
  glm::vec3 toVec3() const { return glm::vec3(x,y,z); }
  GLfloat* toGLF3() { return v; }
  
  static Vector3D zero() { return Vector3D(0.0, 0.0, 0.0); }
  static Vector3D one() { return Vector3D(1.0, 1.0, 1.0); }
  
  static Vector3D up() { return Vector3D(0.0, 1.0, 0.0); }
  static Vector3D down() { return Vector3D(0.0, -1.0, 0.0); }
  static Vector3D right() { return Vector3D(1.0, 0.0, 0.0); }
  static Vector3D left() { return Vector3D(-1.0, 0.0, 0.0); }
  static Vector3D forward() { return Vector3D(0.0, 0.0, -1.0); }
  static Vector3D back() { return Vector3D(0.0, 0.0, 1.0); }
};


union Vector4D {
  struct {
    GLfloat x, y, z, w;
  };
  GLfloat v[4];
  
public:
  Vector4D(GLfloat _x, GLfloat _y, GLfloat _z, GLfloat _w) : x(_x), y(_y), z(_z), w(_w) { /* do nothing */ }
  Vector4D(Vector3D _v3, GLfloat _w) : x(_v3.x), y(_v3.y), z(_v3.z), w(_w) { /* do nothing */ }
  
  Vector4D operator+(GLfloat add) { return Vector4D(x+add, y+add, z+add, w+add); }
  Vector4D operator-(GLfloat sub) { return Vector4D(x-sub, y-sub, z-sub, w-sub); }
  Vector4D operator*(GLfloat mul) { return Vector4D(x*mul, y*mul, z*mul, w*mul); }
  Vector4D operator/(GLfloat div) { return Vector4D(x/div, y/div, z/div, w/div); }
  
  glm::vec4 toVec4() const { return glm::vec4(x,y,z,w); }
  GLfloat* toGLF4() { return v; }
  
  static Vector4D zero() { return Vector4D(0.0, 0.0, 0.0, 0.0); }
  static Vector4D one() { return Vector4D(1.0, 1.0, 1.0, 0.0); }
};


#endif /* Vector_h */
