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
  ShaderLocs() { projectionLoc = viewLoc = modelLoc = -1; }
};

class BaseObject3D : public Base3D {

protected:
  GLuint shaderProgram;
  Shaders shaders;
  ShaderLocs sLocs;
  GLint objectColorLoc;
  
  Vertices vertices;
  
public:
  BaseObject3D();
  BaseObject3D(Vector3D _pos);
  virtual ~BaseObject3D();
  virtual void draw();
    
protected:
  void loadShaderProgram(const char* vs = "Default.vert", const char* fs = "Default.frag");
  void setMvpLoc();
  virtual GLuint createModel(GLuint vCnt, const GLfloat (*position)[3], GLuint cCnt, const GLfloat (*color)[4]);
  virtual GLuint createModel(GLuint vCnt, const GLfloat (*position)[3]);
  
private:
  GLuint readyVAO();
  void setVertexBuffer(GLuint vCnt, const GLfloat (*position)[3]);
  void setColorBuffer(GLuint cCnt, const GLfloat (*color)[4]);
  void releaseVAO();
};

#endif /* BaseObject3D_hpp */
