//
//  Square.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/23.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "Square.hpp"

Square::Square(GLfloat x, GLfloat y, GLfloat w, GLfloat h) : square(x,y,w,h) {
  BaseObject::BaseObject();
  shaderProgram = ShaderLoader::loadShaderProgram("point.vert", "pv", "point.frag", "fc");
}

Square::~Square() { /* do nothing */ }

void Square::draw() {
  BaseObject::draw();
  glUseProgram(shaderProgram);
  
  glBindVertexArray(square.vao);
  glDrawArrays(GL_LINE_LOOP, 0, square.count);
}