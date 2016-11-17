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
  mainCamera = (PerspectiveCameraController*)(CameraManager::instance()).getMainCamera();
  mainCamera->translateTo(Vector3D(0.0f, 30.0f, 30.0f));
  mainCamera->rotate(Quaternion(Vector3D::left(), M_PI/4.0f));
  cameraDefaultPosition = mainCamera->getPosition();
  
  ballManager = &(BallManager::instance());
  ballManager->initialize();
  (ObjectManager::instance()).registerObject(ballManager);
  
  boardCtrl = new BoardController(Transform::identity());
  (ObjectManager::instance()).registerObject(boardCtrl);
  boardCtrl->setupStage();
}

void GameManager::start() {
  ballManager->shotWhiteBall();
}


void GameManager::update(GLfloat deltaTime) {
//  mainCamera->translateTo(cameraDefaultPosition + Vector3D::forward() * sinf(glfwGetTime() * 3.0f));
//  mainCamera->translateTo(cameraDefaultPosition + Vector3D::up()*30.0f + Vector3D::down() * glfwGetTime());
}

void GameManager::destroy() {
  ballManager = nullptr;
  
  delete boardCtrl;
  boardCtrl = nullptr;
}

NS_END
