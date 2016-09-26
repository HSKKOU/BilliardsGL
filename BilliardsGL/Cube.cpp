//
//  Cube.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/25.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "Cube.hpp"

Cube::Cube(const Vector3D _center, const Vector3D _size) : BaseObject3D(_center), cube(_center, _size) {
  loadShaderProgram();
  setMvpLoc();
}

Cube::~Cube() { /* do nothing */ }

void Cube::loadShaderProgram() {
  shaderProgram = ShaderLoader::loadShaderProgram("camera.vert", "pv", "camera.frag", "fc");
}

void Cube::draw() {
  BaseObject3D::draw();
  
  GLfloat mvp[4][4] = {
    { 1.0, 0.0, 0.0, 0.0 },
    { 0.0, 1.0, 0.0, 0.0 },
    { 0.0, 0.0, 1.0, 0.0 },
    { 0.0, 0.0, 0.0, 1.0 }
  };
  
  glUniformMatrix4fv(mvpLoc, 1, GL_FALSE, &mvp[0][0]);

  glUseProgram(shaderProgram);
  
  glBindVertexArray(cube.vao);
  glDrawArrays(GL_TRIANGLES, 0, cube.count);
}