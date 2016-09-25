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
  
  square = new Square(0.0f, 0.0f, 0.5f, 0.5f);
  
  while (window.shouldClose() == GL_FALSE) {
    fps.update(glfwGetTime());
    
    mainLoop();
  }
  
  delete square;
  square = nullptr;
}


void GameManager::mainLoop() {
//  std::cout << "main loop" << std::endl;

  glClear(GL_COLOR_BUFFER_BIT);
  
  square->draw();

  window.swapBuffers();
}

Window* GameManager::getWindow() { return &window; }