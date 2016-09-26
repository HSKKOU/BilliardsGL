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
  
//  glEnable(GL_DEPTH_TEST);
//  glDepthFunc(GL_LEQUAL);
//  glDisable(GL_CULL_FACE);
//  glCullFace(GL_BACK);
}

void GameManager::startMainLoop() {
  
  FPSCounter &fps = FPSCounter::instance();
  fps.initialize(glfwGetTime());
  
//  square = new Square(0.0f, 0.0f, 0.5f, 0.5f);
  cube = new Cube(Vector3D(-0.3f, -0.3f, -0.3f), Vector3D(0.6f, 0.6f, 0.6f));
  
  while (window.shouldClose() == GL_FALSE) {
    fps.update(glfwGetTime());
    
    mainLoop();
  }
  
//  delete square;
//  square = nullptr;
}


void GameManager::mainLoop() {
//  std::cout << "main loop" << std::endl;

  glClear(GL_COLOR_BUFFER_BIT);
  
//  square->draw();
  cube->draw();

  window.swapBuffers();
}

Window* GameManager::getWindow() { return &window; }