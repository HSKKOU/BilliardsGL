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

#include "CameraManager.hpp"

struct Vertices {
  GLuint vao;
  GLsizei count;
};

class BaseObject3D : public Base3D {

protected:
  GLuint shaderProgram;
  GLint projectionLoc;
  GLint viewLoc;
  GLint modelLoc;
  Vertices vertices;
  
public:
  BaseObject3D();
  BaseObject3D(Vector3D _pos);
  virtual ~BaseObject3D();
  virtual void draw();
    
protected:
  virtual void loadShaderProgram();
  void setMvpLoc();
  GLuint createModel(GLuint vertices, const GLfloat (*position)[3]);
};

#endif /* BaseObject3D_hpp */
