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
  
  shotButton = new UIButton(Point2D(0.0f, 0.0f), Vector2D(640.0f, 640.0f), ETex::None, UI_ALIGNMENT::None, Color::zero());
  shotButton->setHandler(this);
  (ObjectManager::instance()).registerObject(shotButton);
}

void GameManager::awake() {
  mainCamera = (PerspectiveCameraController*)(CameraManager::instance()).getMainCamera();
  mainCamera->translateTo(Vector3D(0.0f, 100.0f, 0.0f));
  cameraDefaultPosition = mainCamera->getPosition();
  
  ballManager = &(BallManager::instance());
  ballManager->initialize();
  (ObjectManager::instance()).registerObject(ballManager);
  
  boardCtrl = new BoardController(Transform::identity());
  (ObjectManager::instance()).registerObject(boardCtrl);
  boardCtrl->setupStage();
}

void GameManager::start() { /* do nothing */ }


void GameManager::update(GLfloat deltaTime) {
//  mainCamera->translateTo(cameraDefaultPosition + Vector3D::forward() * sinf(glfwGetTime() * 3.0f));
//  mainCamera->translateTo(cameraDefaultPosition + Vector3D::up()*30.0f + Vector3D::down() * glfwGetTime());
}

void GameManager::destroy() {
  ballManager = nullptr;
  SAFE_DELETE(boardCtrl);
}


void GameManager::onButtonDown() {
  std::cout << "button down" << std::endl;
  ballManager->shotWhiteBall();
}
void GameManager::onButtonDownRepeat() {
  //  std::cout << "button down repeat" << std::endl;
}
void GameManager::onButtonUp() {
  std::cout << "button up" << std::endl;
}


NS_END
