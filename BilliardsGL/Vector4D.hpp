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

  Vector4D operator=(const Vector4D & va);
  Vector4D operator+(const GLfloat add) const;
  Vector4D operator+(const Vector4D v4) const;
  Vector4D operator-(const GLfloat sub) const;
  Vector4D operator-(const Vector4D v4) const;
  Vector4D operator*(const GLfloat mul) const;
  Vector4D operator/(const GLfloat div) const;
  GLfloat& operator[](int i);
  
  GLfloat dot(const Vector4D v) const;
  
  GLfloat length() const;
  Vector4D normalize() const;
  
  Vector3D vec3() const;
  
  static Vector4D zero();
  static Vector4D one();
};

typedef Vector4D Color;

NS_END

#endif /* Vector4D_hpp */
