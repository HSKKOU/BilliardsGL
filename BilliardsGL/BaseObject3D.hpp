//
//  BaseObject3D.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/25.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef BaseObject3D_hpp
#define BaseObject3D_hpp

#include "GlobalHeader.h"
#include "Base3D.h"

#include "ShaderLoader.hpp"

#include "CameraManager.hpp"

#include "LightManager.hpp"

struct Vertices {
  GLuint vao;
  GLsizei count;
};

struct Shaders {
  const char* vSrc;
  const char* fSrc;
};

struct ShaderLocs {
  GLint projectionLoc;
  GLint viewLoc;
  GLint modelLoc;
  GLint objectColorLoc;
  GLint lightPosLoc;
  GLint lightColorLoc;
  GLint cameraPosLoc;
  ShaderLocs() { projectionLoc = viewLoc = modelLoc = objectColorLoc = lightPosLoc = lightColorLoc = cameraPosLoc = -1; }
};

struct MVP {
  Matrix4D projection;
  Matrix4D view;
  Matrix4D model;
  MVP() {
    projection = Matrix4D::zero();
    view = Matrix4D::zero();
    model = Matrix4D::zero();
  }
};

typedef Vector4D Color;

class BaseObject3D : public Base3D {

protected:
  GLuint shaderProgram;
  Shaders shaders;
  ShaderLocs sLocs;
  
  Vertices vertices;
  
protected:
  MVP mvp;
  Color objectColor;
  CameraController *targetCamera;
  LightControllerBase *targetLight;
  
public:
  BaseObject3D();
  BaseObject3D(const Vector3D _pos);
  virtual ~BaseObject3D();
  
  // accessor
  Color getObjectColor() const;
  void setObjectColor(const Color c);

  virtual void loadShaderProgram(const char* vs = "Default.vert", const char* fs = "Default.frag");

  virtual void draw() = 0;
  virtual void drawReady();
  virtual void drawRun(int mode = GL_TRIANGLES);
  
protected:
  void setShaderLoc();
  virtual const GLuint createModel(const GLfloat (*vertices)[3+4+3], const GLuint vCnt, const int pCnt, const int cCnt, const int nCnt);
  virtual const GLuint createModel(const GLfloat (*vertices)[3+3], const GLuint vCnt, const int pCnt, const int nCnt);
  virtual const GLuint createModel(const GLfloat (*vertices)[3], const GLuint vCnt, const int pCnt);
  void sendMVP2Shd();
  void sendColor2Shd() const;
  void sendLightInfo2Shd() const;
  void sendCameraPos2Shd() const;
  
private:
  GLuint readyVAO() const;
  void setVertexBuffer(const GLuint vCnt, const GLfloat (*position)[3]) const;
  void setColorBuffer(const GLuint cCnt, const GLfloat (*color)[4]) const;
  void releaseVAO() const;
};

#endif /* BaseObject3D_hpp */
