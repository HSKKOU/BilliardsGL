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
  // create window
  window = new Window(640, 640, "BilliardGL");
  
  // set background color
  glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
}

void GameManager::startMainLoop() {
  // fps counter created
  FPSCounter &fps = FPSCounter::instance();
  fps.initialize(glfwGetTime());
  
  glEnable(GL_DEPTH_BUFFER);
  glEnable(GL_CULL_FACE);
  
  // Light Initialized
  LightManager &lightManager = LightManager::instance();
  lightManager.initialize();
  
  // Camera Initialized
  CameraManager &cameraManager = CameraManager::instance();
  cameraManager.initialize();
  cameraManager.getCamera()->setPerspective(45.0f, 1.0f, 0.5f, 100.0f);

//  square = new Square(0.0f, 0.0f, 0.5f, 0.5f);
  cube = new Cube(Vector3D(0.0f, 0.0f, 0.0f), Vector3D(1.0f, 1.0f, 1.0f));
//  cube = new Cube(Vector3D(-2.0f, -1.0f, 0.0f), Vector3D(1.0f, 1.0f, 1.0f));
  
  // game loop
  while (window->shouldClose() == GL_FALSE) {
    fps.update(glfwGetTime());
    mainLoop();
  }
  
//  delete square;
//  square = nullptr;
  
  delete window;
  window = nullptr;
}


void GameManager::mainLoop() {
//  std::cout << "main loop" << std::endl;

  // reset buffer
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  (LightManager::instance()).updateLights();
  
//  square->draw();
  cube->draw();

  // change another drawing buffer
  window->swapBuffers();
}
