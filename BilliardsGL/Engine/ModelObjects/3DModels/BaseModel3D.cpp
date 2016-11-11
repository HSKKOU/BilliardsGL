//
//  BaseModel3D.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/25.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "BaseModel3D.hpp"

NS_ENGINE_MODEL

BaseModel3D::BaseModel3D(Vector3D _pos)
: Base3D(_pos)
, shaderProgram(-1)
, shaders(Shaders())
, sLocs(ShaderLocs())
, vertices(Vertices())
, mvp(MVP())
, objectColor(Vector4D(0.5f, 0.5f, 0.5f, 1.0f))
, textureId(0)
, targetCamera((CameraManager::instance()).getMainCamera())
, targetLight((LightManager::instance()).getLight())
{ /* do nothing */ }

BaseModel3D::~BaseModel3D() { /* do nothing */ }

Color BaseModel3D::getObjectColor() const { return objectColor; }
void BaseModel3D::setObjectColor(Color c) { objectColor = c; }



// drawing methods
void BaseModel3D::draw() {
  drawReady();
  sendParams2Shd();
  drawRun();
}

void BaseModel3D::drawReady() {
  // set vertices and shader
  glUseProgram(shaderProgram);
  glBindVertexArray(vertices.vao);
  
  // reset MVP matrix
  mvp.projection = targetCamera->getProjectionMatrix();
  mvp.view = targetCamera->getViewMatrix();
  mvp.model = Matrix4D(1.0f);
  mvp.model = Matrix4D::translate(mvp.model, transform.position);
  mvp.model = Matrix4D::rotate(mvp.model, transform.rotation);
  mvp.model = Matrix4D::scale(mvp.model, transform.scale);
}

void BaseModel3D::drawRun(int mode) {
  glDrawArrays(mode, 0, vertices.count);
  
  // release drawing buffers
  glBindVertexArray(0);
  for (int i=0; i<static_cast<int>(AttribLoc::NUM); i++) { glDisableVertexAttribArray(i); }
  glUseProgram(0);
  glFlush();
}

void BaseModel3D::sendParams2Shd() {
  sendMVP2Shd();
  sendColor2Shd();
  sendLightInfo2Shd();
  sendTexture2Shd();
}
void BaseModel3D::sendMVP2Shd() {
  glUniformMatrix4fv(sLocs.projectionLoc, 1, GL_FALSE, &mvp.projection[0][0]);
  glUniformMatrix4fv(sLocs.viewLoc, 1, GL_FALSE, &mvp.view[0][0]);
  glUniformMatrix4fv(sLocs.modelLoc, 1, GL_FALSE, &mvp.model[0][0]);
}

void BaseModel3D::sendColor2Shd() const { glUniform4fv(sLocs.objectColorLoc, 1, objectColor.v); }

void BaseModel3D::sendLightInfo2Shd() const {
  glUniform3fv(sLocs.lightPosLoc, 1, (targetLight->getPosition()).v);
  glUniform4fv(sLocs.lightColorLoc, 1, (targetLight->getColor()).v);
}

void BaseModel3D::sendCameraPos2Shd() const { glUniform3fv(sLocs.cameraPosLoc, 1, (targetCamera->getPosition()).v); }

void BaseModel3D::sendTexture2Shd() const {
  if (textureId == 0) { return; }
  glBindTexture(GL_TEXTURE_2D, textureId);
  glDrawElements(GL_TRIANGLES, vertices.count, GL_UNSIGNED_INT, 0);
}




// related to shader
void BaseModel3D::loadShaderProgram(const char* vs, const char* fs) {
  shaders.vSrc = vs;
  shaders.fSrc = fs;
  shaderProgram = ShaderLoader::loadShaderProgram(shaders.vSrc, "pv", shaders.fSrc, "fc");
  setShaderLoc();
}

void BaseModel3D::setShaderLoc() {
  sLocs.projectionLoc = glGetUniformLocation(shaderProgram, "projection");
  sLocs.viewLoc = glGetUniformLocation(shaderProgram, "view");
  sLocs.modelLoc = glGetUniformLocation(shaderProgram, "model");
  
  sLocs.objectColorLoc = glGetUniformLocation(shaderProgram, "objectColor");
  
  sLocs.lightPosLoc = glGetUniformLocation(shaderProgram, "lightPos");
  sLocs.lightColorLoc = glGetUniformLocation(shaderProgram, "lightColor");
  
  sLocs.cameraPosLoc = glGetUniformLocation(shaderProgram, "cameraPos");
}


// related to texture
void BaseModel3D::setTexture(ETex tex) { textureId = (TextureLoader::instance()).getTextureId(tex); }



const GLuint BaseModel3D::createModel(const GLfloat (*vertices)[3], const GLuint vCnt, const int pCnt) {
  GLuint vao = readyVAO();
  setVertexBuffer(vertices, pCnt*vCnt);
  
  setPositionBuffer (pCnt, 0);
  
  releaseBuffer();
  return vao;
}

const GLuint BaseModel3D::createModel(const GLfloat (*vertices)[3+3], const GLuint vCnt, const int pCnt, const int nCnt) {
  GLuint vao = readyVAO();
  setVertexBuffer(vertices, (pCnt+nCnt)*vCnt);
  
  setPositionBuffer (pCnt+nCnt, 0);
  setNormalBuffer   (pCnt+nCnt, pCnt);
  
  releaseBuffer();
  return vao;
}

const GLuint BaseModel3D::createModel(const GLfloat (*vertices)[3+2+3], const GLuint vCnt, const int pCnt, const int uvCnt, const int nCnt) {
  GLuint vao = readyVAO();
  setVertexBuffer(vertices, (pCnt+uvCnt+nCnt)*vCnt);
  
//  for (int i=0; i<vCnt; i++) {
//    std::cout
//    << "vs[" << i << "] : "
//    << "(" << vertices[i][0] << "," << vertices[i][1] << "," << vertices[i][2] << ") "
//    << "(" << vertices[i][3] << "," << vertices[i][4] << ") "
//    << "(" << vertices[i][5] << "," << vertices[i][6] << "," << vertices[i][7] << ") "
//    << std::endl;
//  }
  
  setPositionBuffer (pCnt+uvCnt+nCnt, 0);
  setUVBuffer       (pCnt+uvCnt+nCnt, pCnt);
  setNormalBuffer   (pCnt+uvCnt+nCnt, pCnt+uvCnt);
  
  releaseBuffer();
  return vao;
}





GLuint BaseModel3D::readyVAO() const {
  GLuint vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);
  return vao;
}

GLuint BaseModel3D::setVertexBuffer(const GLfloat (*vertices)[3], const int vSize) const {
  GLuint vertexBuffer;
  glGenBuffers(1, &vertexBuffer);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*vSize, vertices, GL_STATIC_DRAW);
  return vertexBuffer;
}

GLuint BaseModel3D::setVertexBuffer(const GLfloat (*vertices)[3+3], const int vSize) const {
  GLuint vertexBuffer;
  glGenBuffers(1, &vertexBuffer);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*vSize, vertices, GL_STATIC_DRAW);
  return vertexBuffer;
}

GLuint BaseModel3D::setVertexBuffer(const GLfloat (*vertices)[3+2+3], const int vSize) const {
  GLuint vertexBuffer;
  glGenBuffers(1, &vertexBuffer);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*vSize, vertices, GL_STATIC_DRAW);
  return vertexBuffer;
}

void BaseModel3D::setPositionBuffer(const int vCnt, const int offset) const {
  GLuint loc = static_cast<GLuint>(AttribLoc::POSITION);
  setEachVertexBuffer(loc, 3, vCnt, offset);
}

void BaseModel3D::setNormalBuffer(const int vCnt, const int offset) const {
  GLuint loc = static_cast<GLuint>(AttribLoc::NORMAL);
  glBindAttribLocation(shaderProgram, loc, "normal");
  setEachVertexBuffer(loc, 3, vCnt, offset);
}

void BaseModel3D::setUVBuffer(const int vCnt, const int offset) const {
  GLuint loc = static_cast<GLuint>(AttribLoc::UV);
  glBindAttribLocation(shaderProgram, loc, "uv");
  setEachVertexBuffer(loc, 2, vCnt, offset);
}

void BaseModel3D::setEachVertexBuffer(const GLuint loc, const int size, const int vCnt, const int offset) const {
  glEnableVertexAttribArray(loc);
  glVertexAttribPointer(loc, size, GL_FLOAT, GL_FALSE, vCnt*sizeof(GLfloat), (GLfloat*)(offset*sizeof(GLfloat)));
}

void BaseModel3D::releaseBuffer() const {
  glBindVertexArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

NS_END2
