//
//  Vector2D.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/11.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "Vector2D.hpp"

NS_ENGINE

Vector2D::Vector2D(const GLfloat _x, const GLfloat _y) : x(_x), y(_y) { /* do nothing */ }

Vector2D Vector2D::operator=(const Vector2D &va) {
  this->x = va.x;
  this->y = va.y;
  return *this;
}
Vector2D Vector2D::operator+(const GLfloat add) const { return Vector2D(x+add, y+add); }
Vector2D Vector2D::operator+(const Vector2D va) const { return Vector2D(x+va.x, y+va.y); }
Vector2D Vector2D::operator+=(const Vector2D &va) { *this=*this+va; return *this; }
Vector2D Vector2D::operator-(const GLfloat sub) const { return Vector2D(x-sub, y-sub); }
Vector2D Vector2D::operator-(const Vector2D vs) const { return Vector2D(x-vs.x, y-vs.y); }
Vector2D Vector2D::operator*(const GLfloat mul) const { return Vector2D(x*mul, y*mul); }
Vector2D Vector2D::operator/(const GLfloat div) const { return Vector2D(x/div, y/div); }

Vector2D Vector2D::divide(const GLfloat divX, const GLfloat divY) const { return Vector2D(x/divX, y/divY); }

GLfloat Vector2D::dot(const Vector2D v) const { return x*v.x + y*v.y; }

GLfloat Vector2D::squareLength() const { return x*x+y*y; }
GLfloat Vector2D::length() const { return (GLfloat)sqrt(squareLength()); }
Vector2D Vector2D::normalize() const { return this->operator/(length()); }

Vector2D Vector2D::zero() { return Vector2D(0.0f, 0.0f); }
Vector2D Vector2D::one() { return Vector2D(1.0f, 1.0f); }

Vector2D Vector2D::up() { return Vector2D(0.0f, 1.0f); }
Vector2D Vector2D::down() { return Vector2D(0.0f, -1.0f); }
Vector2D Vector2D::right() { return Vector2D(1.0f, 0.0f); }
Vector2D Vector2D::left() { return Vector2D(-1.0f, 0.0f); }

void Vector2D::printElem() const { std::cout << v[0] << ", " << v[1] << std::endl; }

NS_END
