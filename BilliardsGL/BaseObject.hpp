//
//  BaseObject.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/23.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef BaseObject_hpp
#define BaseObject_hpp

#include "GlobalHeader.h"

struct BaseModel {
  GLuint vao;
  GLsizei count;
  
public:
  void initializeModel(GLfloat (*position)[2], int cnt) {
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

class BaseObject {
  BaseModel baseModel;
  
public:
  BaseObject();
  virtual ~BaseObject();
  void draw();
};

#endif /* BaseObject_hpp */
