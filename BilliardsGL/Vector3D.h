//
//  Vector3D.h
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/25.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef Vector3D_h
#define Vector3D_h

#include "GlobalHeader.h"

#include "glm/glm.hpp"

struct Vector3D {
  GLfloat x, y, z;
  
public:
  Vector3D(GLfloat _x, GLfloat _y, GLfloat _z) : x(_x), y(_y), z(_z) { /* do nothing */ }
  
  Vector3D operator+(GLfloat add) { return Vector3D(x+add, y+add, z+add); }
  Vector3D operator-(GLfloat sub) { return Vector3D(x-sub, y-sub, z-sub); }
  Vector3D operator*(GLfloat mul) { return Vector3D(x*mul, y*mul, z*mul); }
  Vector3D operator/(GLfloat div) { return Vector3D(x/div, y/div, z/div); }
  
  glm::vec3 toVec3() const { return glm::vec3(x,y,z); }
  
  static Vector3D zero() { return Vector3D(0.0, 0.0, 0.0); }
  static Vector3D one() { return Vector3D(1.0, 1.0, 1.0); }
  
  static Vector3D up() { return Vector3D(0.0, 1.0, 0.0); }
  static Vector3D down() { return Vector3D(0.0, -1.0, 0.0); }
  static Vector3D right() { return Vector3D(1.0, 0.0, 0.0); }
  static Vector3D left() { return Vector3D(-1.0, 0.0, 0.0); }
  static Vector3D forward() { return Vector3D(0.0, 0.0, -1.0); }
  static Vector3D back() { return Vector3D(0.0, 0.0, 1.0); }
};

#endif /* Vector3D_h */
