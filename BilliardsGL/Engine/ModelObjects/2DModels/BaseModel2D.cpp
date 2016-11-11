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
{ /* do nothing */ }
BaseModel2D::~BaseModel2D() { /* do nothing */ }


const GLuint BaseModel2D::createModel(const GLfloat (*vertices)[2+2], const GLuint vCnt, const int pCnt, const int uvCnt) {
  GLuint vao = readyVAO();
  setVertexBuffer(vertices, (pCnt+uvCnt)*vCnt);
  
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
