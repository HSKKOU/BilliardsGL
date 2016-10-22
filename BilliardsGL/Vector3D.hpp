//
//  Vector3D.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/22.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef Vector3D_hpp
#define Vector3D_hpp

#include "GlobalHeader.h"
#include <cmath>

NS_ENGINE

union Vector3D {
  struct {
    GLfloat x, y, z;
  };
  GLfloat v[3];
  
public:
  Vector3D(const GLfloat _x, const GLfloat _y, const GLfloat _z);
  
  Vector3D operator+(const GLfloat add);
  Vector3D operator+(const Vector3D va);
  Vector3D operator-(const GLfloat sub);
  Vector3D operator-(const Vector3D vs);
  Vector3D operator*(const GLfloat mul);
  Vector3D operator/(const GLfloat div);
  
  GLfloat dot(const Vector3D v);
  Vector3D cross(const Vector3D v);
  
  GLfloat length();
  Vector3D normalize();
  
  static Vector3D zero();
  static Vector3D one();
  
  static Vector3D up();
  static Vector3D down();
  static Vector3D right();
  static Vector3D left();
  static Vector3D forward();
  static Vector3D back();
  
  void printElem();
};

NS_END

#endif /* Vector3D_hpp */
