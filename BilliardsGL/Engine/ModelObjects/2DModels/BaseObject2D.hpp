//
//  BaseObject2D.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/23.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef BaseObject2D_hpp
#define BaseObject2D_hpp

#include "GlobalHeader.h"

NS_ENGINE_MODEL

struct BaseModel2D {
  GLuint vao;
  GLsizei count;
  
public:
  void initializeModel(const GLfloat (*position)[2], int cnt) {
    vao = createObject(cnt, position);
    count = cnt;
  }
  
private:
  GLuint createObject (GLuint vertices, const GLfloat (*position)[2]) {
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*2*vertices, position, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);
    
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    return vao;
  }
};

class BaseObject2D {
  
protected:
  GLuint shaderProgram;
  GLint sizeLoc;
  GLint scaleLoc;
  
public:
  BaseObject2D();
  virtual ~BaseObject2D();
  virtual void draw();
};

NS_END2

#endif /* BaseObject2D_hpp */
