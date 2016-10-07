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
, fps(FPSCounter::instance())
{ /* do nothing */ }

void GameManager::initialize() {
  // create window
  window = new Window(640, 640, "BilliardGL");
  
  // set background color
  glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
  
  // FPS initialize
  fps.initialize(glfwGetTime());

  // Managers initialize
  lightManager.initialize();
  cameraManager.initialize();
  objectManager.initialize();
}

void GameManager::startMainLoop() {
  window->readyWindow();
  
  cameraManager.getCamera()->setPerspective(45.0f, 1.0f, 0.5f, 100.0f);
  
  objectManager.instantiateObject(ObjectType::CUBE);
  
  // game loop
  while (window->shouldClose() == GL_FALSE) {
    fps.update(glfwGetTime());
    mainLoop();
  }
}


void GameManager::mainLoop() {
  window->resetBuffer();
  
  lightManager.updateLights();
  objectManager.updateObject();

  // change another drawing buffer
  window->swapBuffers();
}

void GameManager::finishMainLoop() {
  delete window;
  window = nullptr;
}
