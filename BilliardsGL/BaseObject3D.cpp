//
//  BaseObject3D.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/25.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "BaseObject3D.hpp"

BaseObject3D::BaseObject3D() {
  
}

BaseObject3D::~BaseObject3D() {
  /* do nothing */
}

void BaseObject3D::loadShaderProgram() {
  std::cout << "illegal load shader" << std::endl;
}

void BaseObject3D::setMvpLoc() {
  mvpLoc = glGetUniformLocation(shaderProgram, "MVP");
}

void BaseObject3D::draw() {
  glMatrixMode(GL_PROJECTION_MATRIX);
  glLoadIdentity();
  
  glMatrixMode(GL_MODELVIEW_MATRIX);
  
  
}
