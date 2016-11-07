//
//  Square.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/23.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "Square.hpp"

NS_ENGINE_MODEL

Square::Square(GLfloat x, GLfloat y, GLfloat w, GLfloat h) : square(x,y,w,h) {
  BaseObject2D::BaseObject2D();
//  shaderProgram = Engine::Util::ShaderLoader::loadShaderProgram("point.vert", "pv", "point.frag", "fc");
}

Square::~Square() { /* do nothing */ }

void Square::draw() {
  BaseObject2D::draw();
  glUseProgram(shaderProgram);
  
  glBindVertexArray(square.vao);
  glDrawArrays(GL_TRIANGLES, 0, square.count);
}

NS_END2