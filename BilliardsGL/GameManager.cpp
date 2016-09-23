//
//  GameManager.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/15.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "GameManager.hpp"

GameManager::GameManager() { /* do nothing */ }

void GameManager::initialize() {
  // set background color
  glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
}

void GameManager::startMainLoop() {
  
  FPSCounter &fps = FPSCounter::instance();
  fps.initialize(glfwGetTime());

  while (window.shouldClose() == GL_FALSE) {
    fps.update(glfwGetTime());
    
    mainLoop();
  }
}


void GameManager::mainLoop() {
//  std::cout << "main loop" << std::endl;

//  const GLuint program = loadProgram("point.vert", "pv", "point.frag", "fc");
//
//  const GLint sizeLoc = glGetUniformLocation(program, "size");
//  const GLint scaleLoc = glGetUniformLocation(program, "scale");
//  const GLint positionLoc = glGetUniformLocation(program, "position");
//
//  const Object object = createRectangle();

  glClear(GL_COLOR_BUFFER_BIT);

//  glUseProgram(program);
//
//  glUniform2fv(sizeLoc, 1, window.getSize());
//  glUniform1f(scaleLoc, window.getScale());
//  glUniform2fv(positionLoc, 1, window.getPosition());
//
//  glBindVertexArray(object.vao);
//  glDrawArrays(GL_LINE_LOOP, 0, object.count);
  
  window.swapBuffers();
}