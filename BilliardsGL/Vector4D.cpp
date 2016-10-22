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

Vector4D Vector4D::operator+(const GLfloat add) const { return Vector4D(x+add, y+add, z+add, w+add); }
Vector4D Vector4D::operator+(const Vector4D v4) const { return Vector4D(x+v4.x, y+v4.y, z+v4.z, w+v4.w); }
Vector4D Vector4D::operator-(const GLfloat sub) const { return Vector4D(x-sub, y-sub, z-sub, w-sub); }
Vector4D Vector4D::operator-(const Vector4D v4) const { return Vector4D(x-v4.x, y-v4.y, z-v4.z, w-v4.w); }
Vector4D Vector4D::operator*(const GLfloat mul) const { return Vector4D(x*mul, y*mul, z*mul, w*mul); }
Vector4D Vector4D::operator/(const GLfloat div) const { return Vector4D(x/div, y/div, z/div, w/div); }
GLfloat& Vector4D::operator[](int i) { return v[i]; }

GLfloat Vector4D::dot(const Vector4D v) const { return x*v.x+y*v.y+z*v.z+w*v.w; }

GLfloat Vector4D::length() const { return (GLfloat)sqrt(x*x+y*y+z*z+w*w); }
Vector4D Vector4D::normalize() const { return this->operator/(length()); }

Vector3D Vector4D::vec3() const { return Vector3D(x,y,z); }

Vector4D Vector4D::zero() { return Vector4D(0.0f, 0.0f, 0.0f, 0.0f); }
Vector4D Vector4D::one() { return Vector4D(1.0f, 1.0f, 1.0f, 1.0f); }

NS_END
