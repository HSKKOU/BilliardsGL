//
//  Matrix4D.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/22.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef Matrix4D_hpp
#define Matrix4D_hpp

#include "GlobalHeader.h"
#include <cmath>

#include "Vector3D.hpp"
#include "Quaternion.hpp"

NS_ENGINE

struct Matrix4D {
  GLfloat m[4][4];
  
public:
  Matrix4D();
  Matrix4D(GLfloat val);

  Matrix4D operator+(Matrix4D _m);
  Matrix4D operator-(Matrix4D _m);
  Matrix4D operator*(Matrix4D _m);
  GLfloat* operator[](int i);
  GLfloat& operator()(int i, int j);
  
  static Matrix4D one();
  static Matrix4D zero();
  static Matrix4D translate(Matrix4D m, Vector3D v);
  static Matrix4D rotate(Matrix4D m, Vector3D v, GLfloat t);
  static Matrix4D rotate(Matrix4D m, Quaternion q);
  static Matrix4D rotateX(Matrix4D m, GLfloat t);
  static Matrix4D rotateY(Matrix4D m, GLfloat t);
  static Matrix4D rotateZ(Matrix4D m, GLfloat t);
  static Matrix4D scale(Matrix4D m, Vector3D v);
  
  static Matrix4D fromQuaternion(Quaternion q);
  
  void printElem();
};

NS_END

#endif /* Matrix4D_hpp */
