//
//  Vector4D.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/22.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef Vector4D_hpp
#define Vector4D_hpp

#include "GlobalHeader.h"
#include <cmath>

#include "Vector3D.hpp"

NS_ENGINE

union Vector4D {
  struct {
    GLfloat x, y, z, w;
  };
  GLfloat v[4];
  
public:
  Vector4D(const GLfloat _x, const GLfloat _y, const GLfloat _z, const GLfloat _w);
  Vector4D(const Vector3D _v3, const GLfloat _w);
  
  Vector4D operator+(const GLfloat add);
  Vector4D operator-(const GLfloat sub);
  Vector4D operator*(const GLfloat mul);
  Vector4D operator/(const GLfloat div);
  
  static Vector4D zero();
  static Vector4D one();
};

NS_END

#endif /* Vector4D_hpp */
