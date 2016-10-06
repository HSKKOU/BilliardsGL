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
, vertices(Vertices())
, mvp(MVP())
, objectColor(Vector4D::zero())
, targetCamera((CameraManager::instance()).getCamera())
, targetLight((LightManager::instance()).getLight())
{ /* do nothing */ }

BaseObject3D::~BaseObject3D() { /* do nothing */ }

Color BaseObject3D::getObjectColor() { return objectColor; }
void BaseObject3D::setObjectColor(Color c) { objectColor = c; }



// drawing methods
void BaseObject3D::drawReady() {
//  glMatrixMode(GL_PROJECTION_MATRIX);
//  glLoadIdentity();
//  glMatrixMode(GL_MODELVIEW_MATRIX);
  
  mvp.projection = targetCamera->getProjection();
  mvp.view = targetCamera->getViewMatrix();
}
void BaseObject3D::drawRun() {
  glUseProgram(shaderProgram);
  glBindVertexArray(vertices.vao);
  glDrawArrays(GL_TRIANGLES, 0, vertices.count);
  glFlush();
}

void BaseObject3D::sendMVP2Shd() {
  glUniformMatrix4fv(sLocs.projectionLoc, 1, GL_FALSE, &mvp.projection[0][0]);
  glUniformMatrix4fv(sLocs.viewLoc, 1, GL_FALSE, &mvp.view[0][0]);
  glUniformMatrix4fv(sLocs.modelLoc, 1, GL_FALSE, &mvp.model[0][0]);
}

void BaseObject3D::sendColor2Shd() { glUniform4fv(sLocs.objectColorLoc, 1, objectColor.v); }

void BaseObject3D::sendLightInfo2Shd() {
  glUniform3fv(sLocs.lightPosLoc, 1, (targetLight->getPosition()).v);
  glUniform4fv(sLocs.lightColorLoc, 1, (targetLight->getColor()).v);
}



// related to shader
void BaseObject3D::loadShaderProgram(const char* vs, const char* fs) {
  shaders.vSrc = vs;
  shaders.fSrc = fs;
  shaderProgram = ShaderLoader::loadShaderProgram(shaders.vSrc, "pv", shaders.fSrc, "fc");
  setShaderLoc();
}

void BaseObject3D::setShaderLoc() {
  sLocs.projectionLoc = glGetUniformLocation(shaderProgram, "projection");
  sLocs.viewLoc = glGetUniformLocation(shaderProgram, "view");
  sLocs.modelLoc = glGetUniformLocation(shaderProgram, "model");
  
  sLocs.objectColorLoc = glGetUniformLocation(shaderProgram, "objectColor");
  
  sLocs.lightPosLoc = glGetUniformLocation(shaderProgram, "lightPos");
  sLocs.lightColorLoc = glGetUniformLocation(shaderProgram, "lightColor");
}

GLuint BaseObject3D::createModel(const GLfloat (*vertices)[3+4+3], const GLuint vCnt, const int pCnt, const int cCnt, const int nCnt) {
  GLuint vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);
  
  GLuint vertexBuffer;
  glGenBuffers(1, &vertexBuffer);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*(pCnt+cCnt+nCnt)*vCnt, vertices, GL_STATIC_DRAW);
  
  glBindAttribLocation(shaderProgram, 1, "color");
  glBindAttribLocation(shaderProgram, 2, "normal");
  
  // position
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, (pCnt+cCnt+nCnt)*sizeof(GLfloat), (GLvoid*)0);
  glEnableVertexAttribArray(0);

  // color
  glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, (pCnt+cCnt+nCnt)*sizeof(GLfloat), (GLvoid*)(pCnt*sizeof(GLfloat)));
  glEnableVertexAttribArray(1);
  
  // normal
//  glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, (pCnt+cCnt+nCnt)*sizeof(GLfloat), (GLvoid*)((pCnt+cCnt)*sizeof(GLfloat)));
//  glEnableVertexAttribArray(2);

  // release buffer
  glBindVertexArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  return vao;
}

GLuint BaseObject3D::createModel(const GLfloat (*vertices)[3+3], const GLuint vCnt, const int pCnt, const int nCnt) {
  GLuint vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);
  
  GLuint vertexBuffer;
  glGenBuffers(1, &vertexBuffer);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*(pCnt+nCnt)*vCnt, vertices, GL_STATIC_DRAW);
  
  glBindAttribLocation(shaderProgram, 1, "normal");
  
  // position
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, (pCnt+nCnt)*sizeof(GLfloat), (GLvoid*)0);
  glEnableVertexAttribArray(0);
  
  // normal
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, (pCnt+nCnt)*sizeof(GLfloat), (GLvoid*)(pCnt*sizeof(GLfloat)));
  glEnableVertexAttribArray(1);
  
  // release buffer
  glBindVertexArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  
  return vao;
}
