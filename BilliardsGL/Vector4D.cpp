//
//  Vector4D.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/22.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "Vector4D.hpp"

NS_ENGINE

Vector4D::Vector4D(const GLfloat _x, const GLfloat _y, const GLfloat _z, const GLfloat _w) : x(_x), y(_y), z(_z), w(_w) { /* do nothing */ }
Vector4D::Vector4D(const Vector3D _v3, const GLfloat _w) : x(_v3.x), y(_v3.y), z(_v3.z), w(_w) { /* do nothing */ }

Vector4D Vector4D::operator+(const GLfloat add) { return Vector4D(x+add, y+add, z+add, w+add); }
Vector4D Vector4D::operator-(const GLfloat sub) { return Vector4D(x-sub, y-sub, z-sub, w-sub); }
Vector4D Vector4D::operator*(const GLfloat mul) { return Vector4D(x*mul, y*mul, z*mul, w*mul); }
Vector4D Vector4D::operator/(const GLfloat div) { return Vector4D(x/div, y/div, z/div, w/div); }

Vector4D Vector4D::zero() { return Vector4D(0.0f, 0.0f, 0.0f, 0.0f); }
Vector4D Vector4D::one() { return Vector4D(1.0f, 1.0f, 1.0f, 1.0f); }

NS_END
