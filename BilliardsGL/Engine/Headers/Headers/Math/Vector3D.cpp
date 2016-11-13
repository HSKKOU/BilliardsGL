//
//  Vector3D.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/22.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "Vector3D.hpp"

NS_ENGINE

Vector3D::Vector3D(const GLfloat _x, const GLfloat _y, const GLfloat _z) : x(_x), y(_y), z(_z) { /* do nothing */ }

Vector3D Vector3D::operator=(const Vector3D &va) {
  this->x = va.x;
  this->y = va.y;
  this->z = va.z;
  return *this;
}
Vector3D Vector3D::operator+(const GLfloat add) const { return Vector3D(x+add, y+add, z+add); }
Vector3D Vector3D::operator+(const Vector3D va) const { return Vector3D(x+va.x, y+va.y, z+va.z); }
Vector3D Vector3D::operator+=(const Vector3D &va) { *this=*this+va; return *this; }
Vector3D Vector3D::operator-(const GLfloat sub) const { return Vector3D(x-sub, y-sub, z-sub); }
Vector3D Vector3D::operator-(const Vector3D vs) const { return Vector3D(x-vs.x, y-vs.y, z-vs.z); }
Vector3D Vector3D::operator*(const GLfloat mul) const { return Vector3D(x*mul, y*mul, z*mul); }
Vector3D Vector3D::operator/(const GLfloat div) const { return Vector3D(x/div, y/div, z/div); }

bool Vector3D::operator==(const Vector3D v) { return x==v.x && y==v.y && z==v.z; }

GLfloat Vector3D::dot(const Vector3D v) const { return x*v.x+y*v.y+z*v.z; }
Vector3D Vector3D::cross(const Vector3D v) const { return Vector3D(y*v.z-z*v.y, z*v.x-x*v.z, x*v.y-y*v.x); }

GLfloat Vector3D::length() const { return (GLfloat)sqrt(x*x+y*y+z*z); }
GLfloat Vector3D::squareLength() const { return x*x+y*y+z*z; }
Vector3D Vector3D::normalize() const { return this->operator/(length()); }

Vector3D Vector3D::zero() { return Vector3D(0.0f, 0.0f, 0.0f); }
Vector3D Vector3D::one() { return Vector3D(1.0f, 1.0f, 1.0f); }

Vector3D Vector3D::up() { return Vector3D(0.0f, 1.0f, 0.0f); }
Vector3D Vector3D::down() { return Vector3D(0.0f, -1.0f, 0.0f); }
Vector3D Vector3D::right() { return Vector3D(1.0f, 0.0f, 0.0f); }
Vector3D Vector3D::left() { return Vector3D(-1.0f, 0.0f, 0.0f); }
Vector3D Vector3D::forward() { return Vector3D(0.0f, 0.0f, -1.0f); }
Vector3D Vector3D::back() { return Vector3D(0.0f, 0.0f, 1.0f); }

void Vector3D::printElem() const {
  std::cout << v[0] << ", " << v[1] << ", " << v[2] << std::endl;
}

NS_END
