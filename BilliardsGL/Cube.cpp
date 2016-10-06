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

//  loadShaderProgram();
  loadShaderProgram("LightTest.vert", "LightTest.frag");
  objectColorLoc = glGetUniformLocation(shaderProgram, "objectColor");

//  GLfloat color[6*2*3][4];
//  srand((unsigned int)time(NULL));
//  for (int i=0; i<6*2*3; i++) { for (int j=0; j<4; j++) { color[i][j] = rand()%10000/10000.0f; } }

  GLsizei siz = sizeof(vPos)/sizeof(vPos[0]);
  vertices.count = siz;
//  vertices.vao = createModel(siz, vPos, sizeof(color)/sizeof(color[0]), color);
  vertices.vao = createModel(siz, vPos);
}

Cube::~Cube() { /* do nothing */ }

void Cube::draw() {
  BaseObject3D::draw();
  
  CameraController *camera0 = (CameraManager::instance()).getCamera();

//  Vector3D camera0Pos = camera0.getPosition();
//  GLfloat radius = camera0Pos.length();
//  camera0Pos.x = sin(glfwGetTime()) * radius;
//  camera0Pos.z = cos(glfwGetTime()) * radius;
//  camera0.setPosition(camera0Pos);
//  camera0.lookAt(position);

  Matrix4D projection = camera0->getProjection();

  Matrix4D view = camera0->getViewMatrix();
  
  Matrix4D model = Matrix4D(1.0f);
  model = Matrix4D::translate(model, Vector3D((GLfloat)glfwGetTime()*0.5f, 0.0f, 0.0f));
  model = Matrix4D::rotate(model, Vector3D(1.0f, 1.0f, 1.0f).normalize(), (GLfloat)glfwGetTime());
//  model = Matrix4D::scale(model, Vector3D(1.0f, (GLfloat)glfwGetTime(), 1.0f));

  glUniformMatrix4fv(sLocs.projectionLoc, 1, GL_FALSE, &projection[0][0]);
  glUniformMatrix4fv(sLocs.viewLoc, 1, GL_FALSE, &view[0][0]);
  glUniformMatrix4fv(sLocs.modelLoc, 1, GL_FALSE, &model[0][0]);
  
  GLfloat color[4] = { 1.0f, 0.0f, 0.0f, 1.0f };
  glUniform4fv(objectColorLoc, 1, color);

  glUseProgram(shaderProgram);
  
  glBindVertexArray(vertices.vao);
  glDrawArrays(GL_TRIANGLES, 0, vertices.count);
  
  glFlush();
}
