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
, Engine::Model::BaseModel()
, mvp(MVP())
, targetCamera((CameraManager::instance()).getMainCamera())
, targetLight((LightManager::instance()).getLight())
{ /* do nothing */ }

BaseModel3D::~BaseModel3D() { /* do nothing */ }



void BaseModel3D::loadShaderProgram(const char* vs, const char* fs) { BaseModel::loadShaderProgram(vs, fs); }



// drawing methods
void BaseModel3D::drawReady() {
  BaseModel::drawReady();
  
  // reset MVP matrix
  mvp.projection = targetCamera->getProjectionMatrix();
  mvp.view = targetCamera->getViewMatrix();
  mvp.model = Matrix4D::one();
  mvp.model = Matrix4D::translate(mvp.model, transform.position);
  mvp.model = Matrix4D::rotate(mvp.model, transform.rotation);
  mvp.model = Matrix4D::scale(mvp.model, transform.scale);
}


// shader parameters
void BaseModel3D::sendParams2Shd() {
  sendColor2Shd();
  sendMVP2Shd();
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




void BaseModel3D::setShaderLoc() {
  sLocs.projectionLoc = glGetUniformLocation(shaderProgram, "projection");
  sLocs.viewLoc = glGetUniformLocation(shaderProgram, "view");
  sLocs.modelLoc = glGetUniformLocation(shaderProgram, "model");
  
  sLocs.objectColorLoc = glGetUniformLocation(shaderProgram, "objectColor");
  
  sLocs.lightPosLoc = glGetUniformLocation(shaderProgram, "lightPos");
  sLocs.lightColorLoc = glGetUniformLocation(shaderProgram, "lightColor");
  
  sLocs.cameraPosLoc = glGetUniformLocation(shaderProgram, "cameraPos");
}




// model vertices buffering
const GLuint BaseModel3D::createModel(const GLfloat (*vertices)[3+2+3], const GLuint vCnt, const int pCnt, const int uvCnt, const int nCnt) {
  GLuint vao = readyVAO();
  setVertexBuffer(vertices, (pCnt+uvCnt+nCnt)*vCnt);
  
  setPositionBuffer (pCnt+uvCnt+nCnt, 0, 3);
  setUVBuffer       (pCnt+uvCnt+nCnt, pCnt);
  setNormalBuffer   (pCnt+uvCnt+nCnt, pCnt+uvCnt);
  
  releaseBuffer();
  return vao;
}



void BaseModel::setNormalBuffer(const int vCnt, const int offset) const {
  GLuint loc = static_cast<GLuint>(AttribLoc::NORMAL);
  glBindAttribLocation(shaderProgram, loc, "normal");
  setEachVertexBuffer(loc, 3, vCnt, offset);
}

GLuint BaseModel3D::setVertexBuffer(const GLfloat (*vertices)[3+2+3], const int vSize) const {
  GLuint vertexBuffer;
  glGenBuffers(1, &vertexBuffer);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*vSize, vertices, GL_STATIC_DRAW);
  return vertexBuffer;
}


NS_END2
