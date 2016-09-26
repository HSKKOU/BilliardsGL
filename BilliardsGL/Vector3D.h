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

struct Vector3D {
  GLfloat x, y, z;
  
public:
  Vector3D(GLfloat _x, GLfloat _y, GLfloat _z) : x(_x), y(_y), z(_z) { /* do nothing */ }
  
  Vector3D operator/(GLfloat div) { return Vector3D(x/div, y/div, z/div); }
  
  static Vector3D zero() { return Vector3D(0.0, 0.0, 0.0); }
  static Vector3D one() { return Vector3D(1.0, 1.0, 1.0); }
};

#endif /* Vector3D_h */
