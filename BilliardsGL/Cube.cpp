//
//  Cube.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/25.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "Cube.hpp"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

Cube::Cube(const Vector3D _center, const Vector3D _size) : BaseObject3D(_center), size(_size) {
  const GLfloat vPos[6*2*3][3] = {
    // front
    { -size.x, -size.y, -size.z },
    { +size.x, -size.y, -size.z },
    { +size.x, +size.y, -size.z },
    { +size.x, +size.y, -size.z },
    { -size.x, +size.y, -size.z },
    { -size.x, -size.y, -size.z },
    
    // back
    { +size.x, +size.y, +size.z },
    { +size.x, -size.y, +size.z },
    { -size.x, -size.y, +size.z },
    { -size.x, -size.y, +size.z },
    { -size.x, +size.y, +size.z },
    { +size.x, +size.y, +size.z },
    
    // right
    { +size.x, -size.y, -size.z },
    { +size.x, -size.y, +size.z },
    { +size.x, +size.y, +size.z },
    { +size.x, +size.y, +size.z },
    { +size.x, +size.y, -size.z },
    { +size.x, -size.y, -size.z },
    
    // left
    { -size.x, +size.y, +size.z },
    { -size.x, -size.y, +size.z },
    { -size.x, -size.y, -size.z },
    { -size.x, -size.y, -size.z },
    { -size.x, +size.y, -size.z },
    { -size.x, +size.y, +size.z },
    
    // up
    { -size.x, +size.y, -size.z },
    { +size.x, +size.y, -size.z },
    { +size.x, +size.y, +size.z },
    { +size.x, +size.y, +size.z },
    { -size.x, +size.y, +size.z },
    { -size.x, +size.y, -size.z },
    
    // down
    { +size.x, -size.y, +size.z },
    { +size.x, -size.y, -size.z },
    { -size.x, -size.y, -size.z },
    { -size.x, -size.y, -size.z },
    { -size.x, -size.y, +size.z },
    { +size.x, -size.y, +size.z },
  };

  loadShaderProgram("LightTest.vert", "LightTest.frag");

  setObjectColor(Color(1.0f, 0.0f, 0.0, 1.0f));

  GLsizei siz = sizeof(vPos)/sizeof(vPos[0]);
  vertices.count = siz;
  vertices.vao = createModel(siz, vPos);
}

Cube::~Cube() { /* do nothing */ }

void Cube::draw() {
  BaseObject3D::draw();
  
  mvp.model = Matrix4D(1.0f);
  mvp.model = Matrix4D::translate(mvp.model, Vector3D((GLfloat)glfwGetTime()*0.5f, 0.0f, 0.0f));
  mvp.model = Matrix4D::rotate(mvp.model, Vector3D(1.0f, 1.0f, 1.0f).normalize(), (GLfloat)glfwGetTime());
//  mvp.model = Matrix4D::scale(mvp.model, Vector3D(1.0f, (GLfloat)glfwGetTime(), 1.0f));
  
  setObjectColor(Color(0.1f*(GLfloat)glfwGetTime(), 0.0f, 0.0f, 1.0f));

  sendMVP2Shd();
  sendColor2Shd();
  
  glUseProgram(shaderProgram);
  
  glBindVertexArray(vertices.vao);
  glDrawArrays(GL_TRIANGLES, 0, vertices.count);
  
  glFlush();
}
