//
//  BaseObject3D.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/25.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "BaseObject3D.hpp"

BaseObject3D::BaseObject3D() : BaseObject3D(Vector3D::zero()) { /* do nothing */ }
BaseObject3D::BaseObject3D(Vector3D _pos) : Base3D(_pos), vertices(Vertices()) { /* do nothing */ }

BaseObject3D::~BaseObject3D() { /* do nothing */ }

void BaseObject3D::loadShaderProgram() { std::cout << "illegal load shader" << std::endl; }

void BaseObject3D::setMvpLoc() {
  projectionLoc = glGetUniformLocation(shaderProgram, "projection");
  viewLoc = glGetUniformLocation(shaderProgram, "view");
  modelLoc = glGetUniformLocation(shaderProgram, "model");
}

void BaseObject3D::draw() {
  glMatrixMode(GL_PROJECTION_MATRIX);
  glLoadIdentity();
  
  glMatrixMode(GL_MODELVIEW_MATRIX);
}

GLuint BaseObject3D::createModel(GLuint vCnt, const GLfloat (*position)[3]) {
  GLuint vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);
  
  GLuint vbo;
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*3*vCnt, position, GL_STATIC_DRAW);
  
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(0);
  
  glBindVertexArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  
  return vao;
}
