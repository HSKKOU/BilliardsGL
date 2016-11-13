//
//  BaseModel3D.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/25.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef BaseModel3D_hpp
#define BaseModel3D_hpp

#include "Base3D.h"

#include "BaseModel.hpp"

#include "TextureLoader.hpp"

#include "CameraManager.hpp"

#include "LightManager.hpp"

NS_ENGINE_MODEL

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

struct ShaderLocs3D {
  GLint projectionLoc;
  GLint viewLoc;
  GLint modelLoc;
  GLint objectColorLoc;
  GLint lightPosLoc;
  GLint lightColorLoc;
  GLint cameraPosLoc;
  ShaderLocs3D() { projectionLoc = viewLoc = modelLoc = objectColorLoc = lightPosLoc = lightColorLoc = cameraPosLoc = -1; }
};



class BaseModel3D : public Base3D, public BaseModel {

protected:
  MVP mvp;
  ShaderLocs3D sLocs;
  CameraControllerBase *targetCamera;
  LightControllerBase *targetLight;
  
public:
  BaseModel3D();
  BaseModel3D(const Vector3D _pos);
  virtual ~BaseModel3D();

  virtual void loadShaderProgram(const char* vs = "./Shaders/Engine/Default.vert", const char* fs = "./Shaders/Engine/Default.frag");
  
  virtual void drawReady();
  virtual void sendParams2Shd();
    
protected:
  virtual void setShaderLoc();
  virtual const GLuint createModel(const GLfloat (*vertices)[3+2+3], const GLuint vCnt, const int pCnt, const int uvCnt, const int nCnt);

  virtual void sendMVP2Shd();
  virtual void sendColor2Shd() const;
  void sendLightInfo2Shd() const;
  void sendCameraPos2Shd() const;
  
private:
  GLuint setVertexBuffer(const GLfloat (*vertices)[3+2+3], const int vSize) const;
};

NS_END2

#endif /* BaseModel3D_hpp */
