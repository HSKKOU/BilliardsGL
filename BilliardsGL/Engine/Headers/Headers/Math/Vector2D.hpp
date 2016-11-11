//
//  Vector2D.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/11.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef Vector2D_hpp
#define Vector2D_hpp

#include "GlobalHeader.h"
#include <cmath>

NS_ENGINE

union Vector2D {
  struct {
    GLfloat x, y;
  };
  GLfloat v[2];
  
public:
  Vector2D(const GLfloat _x, const GLfloat _y);
  
  Vector2D operator=(const Vector2D &va);
  Vector2D operator+(const GLfloat add) const;
  Vector2D operator+(const Vector2D va) const;
  Vector2D operator+=(const Vector2D &va);
  Vector2D operator-(const GLfloat sub) const;
  Vector2D operator-(const Vector2D vs) const;
  Vector2D operator*(const GLfloat mul) const;
  Vector2D operator/(const GLfloat div) const;
  
  GLfloat dot(const Vector2D v) const;
  
  GLfloat squareLength() const;
  GLfloat length() const;
  Vector2D normalize() const;
  
  static Vector2D zero();
  static Vector2D one();
  
  static Vector2D up();
  static Vector2D down();
  static Vector2D right();
  static Vector2D left();
  
  void printElem() const;
};

NS_END

#endif /* Vector2D_hpp */
