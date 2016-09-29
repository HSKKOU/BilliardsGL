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
  
  CameraController camera0 = (CameraManager::instance()).getCamera();
  
//  Vector3D camera0Pos = camera0.getPosition();
//  GLfloat radius = camera0Pos.length();
//  camera0Pos.x = sin(glfwGetTime()) * radius;
//  camera0Pos.z = cos(glfwGetTime()) * radius;
//  camera0.setPosition(camera0Pos);
//  camera0.lookAt(position);

  glm::mat4 projection = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);
  glm::mat4 view = camera0.getViewMatrix();
  
  Matrix4D model = Matrix4D(1.0f);
  model = Matrix4D::translate(model, Vector3D((GLfloat)glfwGetTime(), 0.0, 0.0));
  model = Matrix4D::rotate(model, Vector3D(1.0, 1.0, 1.0).normalize(), (GLfloat)glfwGetTime());
  model = Matrix4D::scale(model, Vector3D(1.0, (GLfloat)glfwGetTime(), 1.0));

  glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, &projection[0][0]);
  glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
  glUniformMatrix4fv(modelLoc, 1, GL_FALSE, &model[0][0]);

  glUseProgram(shaderProgram);
  
  glBindVertexArray(cube.vao);
  glDrawArrays(GL_TRIANGLES, 0, cube.count);
}