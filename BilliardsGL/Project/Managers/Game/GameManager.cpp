//
//  GameManager.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/15.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "GameManager.hpp"

NS_GAME

GameManager::GameManager()
: cameraDefaultPosition(Vector3D::zero())
{ /* do nothing */ }

GameManager::~GameManager() { /* do nothing */ }

void GameManager::initialize() {
  // set background color
  glClearColor(0.5f, 0.5f, 0.5f, 0.0f);
}

void GameManager::awake() {
//  mainCamera = (PerspectiveCameraController*)(CameraManager::instance()).getMainCamera();
//  cameraDefaultPosition = mainCamera->getPosition();
  
  ballManager = &(BallManager::instance());
  ballManager->initialize();
}

void GameManager::start() {
  ballManager->shotWhiteBall();
}


void GameManager::update(GLfloat deltaTime) {
//  mainCamera->translateTo(cameraDefaultPosition + Vector3D::forward() * sinf(glfwGetTime() * 3.0f));
}

void GameManager::destroy() {
  delete ballManager;
  ballManager = nullptr;
}

NS_END
