//
//  Quaternion.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/22.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef Quaternion_hpp
#define Quaternion_hpp

#include "GlobalHeader.h"
#include <cmath>

#include "Vector3D.hpp"

NS_ENGINE

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
  Quaternion();
  Quaternion(const GLfloat _x, const GLfloat _y, const GLfloat _z, const GLfloat _w);
  Quaternion(const Vector3D axis, const GLfloat angle);
  Quaternion(const GLfloat _x, const GLfloat _y, const GLfloat _z);
  
  Quaternion operator*(Quaternion _q);
  Quaternion& operator*=(Quaternion _q);
  
  static Quaternion one();
};

NS_END
#endif /* Quaternion_hpp */
