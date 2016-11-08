//
//  BaseModel3D.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/25.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef BaseModel3D_hpp
#define BaseModel3D_hpp

#include "GlobalHeader.h"
#include "Base3D.h"

#include "ShaderLoader.hpp"
#include "TextureLoader.hpp"

#include "CameraManager.hpp"

#include "LightManager.hpp"

NS_ENGINE_MODEL

enum class AttribLoc : GLuint {
  POSITION = 0,
  NORMAL,
  UV,
  NUM
};

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

typedef GLuint TextureID;




class BaseModel3D : public Base3D {

protected:
  GLuint shaderProgram;
  Shaders shaders;
  ShaderLocs sLocs;
  
  Vertices vertices;
  
protected:
  MVP mvp;
  Color objectColor;
  TextureID textureId;
  CameraControllerBase *targetCamera;
  LightControllerBase *targetLight;
  
public:
  BaseModel3D();
  BaseModel3D(const Vector3D _pos);
  virtual ~BaseModel3D();
  
  // accessor
  Color getObjectColor() const;
  void setObjectColor(const Color c);

  virtual void loadShaderProgram(const char* vs = "./Shaders/Engine/Default.vert", const char* fs = "./Shaders/Engine/Default.frag");

  virtual void setTexture(Tex tex);
  
  virtual void draw();
  virtual void drawReady();
  virtual void sendParams2Shd();
  virtual void drawRun(int mode = GL_TRIANGLES);
    
protected:
  void setShaderLoc();
  // for Debug
  virtual const GLuint createModel(const GLfloat (*vertices)[3], const GLuint vCnt, const int pCnt);
  // for Debug
  virtual const GLuint createModel(const GLfloat (*vertices)[3+3], const GLuint vCnt, const int pCnt, const int nCnt);
  virtual const GLuint createModel(const GLfloat (*vertices)[3+2+3], const GLuint vCnt, const int pCnt, const int uvCnt, const int nCnt);

  void sendMVP2Shd();
  void sendColor2Shd() const;
  void sendLightInfo2Shd() const;
  void sendCameraPos2Shd() const;
  void sendTexture2Shd() const;
  
private:
  GLuint readyVAO() const;
  // for Debug
  GLuint setVertexBuffer(const GLfloat (*vertices)[3], const int vSize) const;
  // for Debug
  GLuint setVertexBuffer(const GLfloat (*vertices)[3+3], const int vSize) const;
  // for Debug
  GLuint setVertexBuffer(const GLfloat (*vertices)[3+2+3], const int vSize) const;
  void setPositionBuffer(const int vCnt, const int offset) const;
  void setNormalBuffer(const int vCnt, const int offset) const;
  void setUVBuffer(const int vCnt, const int offset) const;
  void setEachVertexBuffer(const GLuint loc, const int size, const int vCnt, const int offset) const;
  void releaseBuffer() const;
};

NS_END2

#endif /* BaseModel3D_hpp */
