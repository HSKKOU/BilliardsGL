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
#include "Vector3D.h"
#include "Base3D.h"

struct BaseModel3D {
  GLuint vao;
  GLsizei count;
  
public:
  void initializeModel(const GLfloat (*position)[3], int cnt) {
    vao = createObject(cnt, position);
    count = cnt;
  }
  
private:
  GLuint createObject (GLuint vertices, const GLfloat (*position)[3]) {
//    glEnableClientState(GL_VERTEX_ARRAY);
//    glEnableClientState(GL_COLOR_ARRAY);
//    glVertexPointer(3, GL_FLOAT, 0, position);
//    glVertexPointer(3, GL_FLOAT, 0, color);
//    glDrawArrays(GL_QUADS, 0, vertices);
//    
//    glDisableClientState(GL_VERTEX_ARRAY);
    
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*3*vertices, position, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);
    
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    return vao;
  }
  
};

class BaseObject3D : Base3D {

protected:
  GLuint shaderProgram;
  GLint mvpLoc;
  
public:
  BaseObject3D();
  BaseObject3D(Vector3D);
  virtual ~BaseObject3D();
  virtual void draw();
    
protected:
  virtual void loadShaderProgram();
  void setMvpLoc();
};

#endif /* BaseObject3D_hpp */
