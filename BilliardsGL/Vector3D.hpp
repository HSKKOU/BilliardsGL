//
//  Vector3D.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/25.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef Vector3D_hpp
#define Vector3D_hpp

#include "GlobalHeader.h"

struct Vector3D {
  GLfloat x, y, z;
  
public:
  Vector3D(GLfloat _x, GLfloat _y, GLfloat _z) : x(_x), y(_y), z(_z) { /* do nothing */ }
  
  Vector3D operator/(GLfloat div) { return Vector3D(x/div, y/div, z/div); }
};

#endif /* Vector3D_hpp */
