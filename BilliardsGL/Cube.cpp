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
  GLfloat vPos[6*2*3][3+3] = {
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
  
  const GLfloat normals[6][3] = {
    { 0.0f, 0.0f,-1.0f },
    { 0.0f, 0.0f, 1.0f },
    { 1.0f, 0.0f, 0.0f },
    {-1.0f, 0.0f, 0.0f },
    { 0.0f, 1.0f, 0.0f },
    { 0.0f,-1.0f, 0.0f },
  };
  for (int i=0; i<6; i++) {
    for (int j=0; j<2*3; j++) {
      for (int k=0; k<3; k++) {
        vPos[i*2*3+j][3+k] = normals[i][k];
      }
    }
  }

  setObjectColor(Color(1.0f, 0.0f, 0.0, 1.0f));

  vertices.count = sizeof(vPos)/sizeof(vPos[0]);
  vertices.vao = createModel(vPos, vertices.count, 3, 3);
}

Cube::~Cube() { /* do nothing */ }

void Cube::draw() {
  drawReady();
  
  mvp.model = Matrix4D(1.0f);
//  mvp.model = Matrix4D::translate(mvp.model, Vector3D((GLfloat)glfwGetTime()*0.5f, 0.0f, 0.0f));
//  mvp.model = Matrix4D::rotate(mvp.model, Vector3D(1.0f, 1.0f, 1.0f).normalize(), (GLfloat)glfwGetTime());
  mvp.model = Matrix4D::scale(mvp.model, Vector3D((GLfloat)glfwGetTime(), 1.0f, (GLfloat)glfwGetTime()));
  
//  setObjectColor(Color(0.1f*(GLfloat)glfwGetTime(), 0.0f, 0.0f, 1.0f));

  sendMVP2Shd();
  sendColor2Shd();
  sendLightInfo2Shd();
  
  drawRun();
}
