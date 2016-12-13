//
//  BaseModel.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/11.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "BaseModel.hpp"

NS_ENGINE_MODEL

BaseModel::BaseModel()
: attribLoc(AttribLoc())
, vertices(Vertices())
, objectColor(Color::one())
, textureId(0)
, shaderProgram(-1)
, shaders(Shaders())
{ /* do nothing */ }
BaseModel::~BaseModel() {
  glDeleteProgram(shaderProgram);
  glDeleteVertexArrays(1, &vertices.vao);
}


// color accessor
Color BaseModel::getObjectColor() const { return objectColor; }
void BaseModel::setObjectColor(Color c) { objectColor = c; }
// texture accessor
void BaseModel::setTexture(ETex tex) { textureId = (TextureLoader::instance()).getTextureId(tex); }



// drawing methods
void BaseModel::draw() {
  drawReady();
  sendParams2Shd();
  drawRun();
}

void BaseModel::drawReady() {
  // set vertices and shader
  glUseProgram(shaderProgram);
  glBindVertexArray(vertices.vao);  
}

void BaseModel::drawRun(int mode) {
  glDrawArrays(mode, 0, vertices.count);
  
  // release drawing buffers
  glBindVertexArray(0);
  for (int i=0; i<attribLoc.num; i++) { glDisableVertexAttribArray(i); }
  glUseProgram(0);
  glFlush();
}



void BaseModel::sendTexture2Shd() const {
  if (textureId == 0) { return; }
  glBindTexture(GL_TEXTURE_2D, textureId);
  glDrawElements(GL_TRIANGLES, vertices.count, GL_UNSIGNED_INT, 0);
}



// related to shader
void BaseModel::loadShaderProgram(const char* vs, const char* fs) {
  shaders.vSrc = vs;
  shaders.fSrc = fs;
  shaderProgram = ShaderLoader::loadShaderProgram(shaders.vSrc, "pv", shaders.fSrc, "fc");
  setShaderLoc();
}




GLuint BaseModel::readyVAO() const {
  GLuint vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);
  return vao;
}

void BaseModel::setPositionBuffer(const int vCnt, const int offset, const int dim) const {
  GLuint loc = attribLoc.position;
  setEachVertexBuffer(loc, dim, vCnt, offset);
}

void BaseModel::setUVBuffer(const int vCnt, const int offset) const {
  GLuint loc = attribLoc.uv;
  glBindAttribLocation(shaderProgram, loc, "uv");
  setEachVertexBuffer(loc, 2, vCnt, offset);
}

void BaseModel::setEachVertexBuffer(const GLuint loc, const int size, const int vCnt, const int offset) const {
  glEnableVertexAttribArray(loc);
  glVertexAttribPointer(loc, size, GL_FLOAT, GL_FALSE, vCnt*sizeof(GLfloat), (GLfloat*)(offset*sizeof(GLfloat)));
}

void BaseModel::releaseBuffer() const {
  glBindVertexArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

NS_END2
