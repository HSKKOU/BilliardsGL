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
  
  Vector3D cameraPos = (CameraManager::instance()).getCamera().getPosition();

  glm::mat4 projection = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);
  glm::mat4 view = glm::lookAt(cameraPos.toVec3(), (Vector3D::zero()).toVec3(), glm::vec3(0.0f, 1.0f, 0.0f));
  glm::mat4 model = glm::mat4(1.0f);
  
  model = glm::rotate(model, (GLfloat)glfwGetTime(), glm::vec3(0.5f,1.0f,0.0f));

  glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, &projection[0][0]);
  glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
  glUniformMatrix4fv(modelLoc, 1, GL_FALSE, &model[0][0]);

  glUseProgram(shaderProgram);
  
  glBindVertexArray(cube.vao);
  glDrawArrays(GL_TRIANGLES, 0, cube.count);
}