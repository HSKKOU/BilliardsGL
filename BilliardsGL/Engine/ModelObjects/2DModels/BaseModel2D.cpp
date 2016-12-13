//
//  BaseModel2D.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/23.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "BaseModel2D.hpp"

NS_ENGINE_MODEL

BaseModel2D::BaseModel2D(Point2D _pos)
: Engine::Base2D(_pos)
, Engine::Model::BaseModel()
{
  attribLoc = AttribLoc(0,1,-1,2);
}
BaseModel2D::~BaseModel2D() {
  glDeleteBuffers(1, &vertexBuffer);
}


void BaseModel2D::loadShaderProgram(const char* vs, const char* fs) { BaseModel::loadShaderProgram(vs, fs); }

void BaseModel2D::setShaderLoc() {
  sLocs.positionLoc = glGetUniformLocation(shaderProgram, "position");
  sLocs.objectColorLoc = glGetUniformLocation(shaderProgram, "objectColor");
}

void BaseModel2D::sendParams2Shd() {
  sendColor2Shd();
  sendPosition2Shd();
  sendTexture2Shd();
}
void BaseModel2D::sendPosition2Shd() const { glUniform2fv(sLocs.positionLoc, 1, position.v); }
void BaseModel2D::sendColor2Shd() const { glUniform4fv(sLocs.objectColorLoc, 1, objectColor.v); }


const GLuint BaseModel2D::createModel(const GLfloat (*vertices)[2+2], const GLuint vCnt, const int pCnt, const int uvCnt) {
  GLuint vao = readyVAO();
  vertexBuffer = setVertexBuffer(vertices, (pCnt+uvCnt)*vCnt);
  
  setPositionBuffer (pCnt+uvCnt, 0, 2);
  setUVBuffer       (pCnt+uvCnt, pCnt);
  
  releaseBuffer();
  return vao;
}

GLuint BaseModel2D::setVertexBuffer(const GLfloat (*vertices)[2+2], const int vSize) const {
  GLuint vertexBuffer;
  glGenBuffers(1, &vertexBuffer);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*vSize, vertices, GL_STATIC_DRAW);
  return vertexBuffer;
}


NS_END2
