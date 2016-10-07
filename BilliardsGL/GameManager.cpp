//
//  GameManager.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/15.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "GameManager.hpp"

GameManager::GameManager()
: lightManager(LightManager::instance())
, cameraManager(CameraManager::instance())
, objectManager(ObjectManager::instance())
{ /* do nothing */ }

void GameManager::initialize() {
  // create window
  window = new Window(640, 640, "BilliardGL");
  
  // set background color
  glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
  
  // Managers initialize
  lightManager.initialize();
  cameraManager.initialize();
}

void GameManager::startMainLoop() {
  // fps counter created
  FPSCounter &fps = FPSCounter::instance();
  fps.initialize(glfwGetTime());
  
  glEnable(GL_DEPTH_BUFFER);
  glEnable(GL_CULL_FACE);
  
  cameraManager.getCamera()->setPerspective(45.0f, 1.0f, 0.5f, 100.0f);
  
  objectManager.instantiateObject(ObjectType::CUBE);
  
  // game loop
  while (window->shouldClose() == GL_FALSE) {
    fps.update(glfwGetTime());
    mainLoop();
  }
  
  delete window;
  window = nullptr;
}


void GameManager::mainLoop() {
//  std::cout << "main loop" << std::endl;

  // reset buffer
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  (LightManager::instance()).updateLights();
  
  objectManager.updateObject();

  // change another drawing buffer
  window->swapBuffers();
}
