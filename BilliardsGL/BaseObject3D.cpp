//
//  BaseObject3D.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/25.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "BaseObject3D.hpp"

BaseObject3D::BaseObject3D(Vector3D _pos)
: Base3D(_pos)
, shaderProgram(-1)
, shaders(Shaders())
, sLocs(ShaderLocs())
, objectColorLoc(-1)
, vertices(Vertices())
{ /* do nothing */ }

BaseObject3D::~BaseObject3D() { /* do nothing */ }

void BaseObject3D::loadShaderProgram(const char* vs, const char* fs) {
  shaders.vSrc = vs;
  shaders.fSrc = fs;
  shaderProgram = ShaderLoader::loadShaderProgram(shaders.vSrc, "pv", shaders.fSrc, "fc");
  setMvpLoc();
}

void BaseObject3D::setMvpLoc() {
  sLocs.projectionLoc = glGetUniformLocation(shaderProgram, "projection");
  sLocs.viewLoc = glGetUniformLocation(shaderProgram, "view");
  sLocs.modelLoc = glGetUniformLocation(shaderProgram, "model");
}

void BaseObject3D::draw() {
  glMatrixMode(GL_PROJECTION_MATRIX);
  glLoadIdentity();
  
  glMatrixMode(GL_MODELVIEW_MATRIX);
}

GLuint BaseObject3D::createModel(GLuint vCnt, const GLfloat (*position)[3], GLuint cCnt, const GLfloat (*color)[4]) {
  GLuint vao = readyVAO();
  setVertexBuffer(vCnt, position);
  setColorBuffer(cCnt, color);
  releaseVAO();
  return vao;
}

GLuint BaseObject3D::createModel(GLuint vCnt, const GLfloat (*position)[3]) {
  GLuint vao = readyVAO();
  setVertexBuffer(vCnt, position);
  releaseVAO();
  return vao;
}

GLuint BaseObject3D::readyVAO() {
  // ready object's vertex array
  GLuint vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);
  return vao;
}

void BaseObject3D::setVertexBuffer(GLuint vCnt, const GLfloat (*position)[3]) {
  // set vertex
  GLuint vertexBuffer;
  glGenBuffers(1, &vertexBuffer);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*3*vCnt, position, GL_STATIC_DRAW);
  
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(0);
}

void BaseObject3D::setColorBuffer(GLuint cCnt, const GLfloat (*color)[4]) {
  // set color
  GLuint colorBuffer;
  glGenBuffers(1, &colorBuffer);
  glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*4*cCnt, color, GL_STATIC_DRAW);
  
//  std::cout << colorLoc << std::endl;
  glVertexAttribPointer(objectColorLoc, 4, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(objectColorLoc);
//  glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);
//  glEnableVertexAttribArray(1);
}

void BaseObject3D::releaseVAO() {
  // release buffer
  glBindVertexArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}
