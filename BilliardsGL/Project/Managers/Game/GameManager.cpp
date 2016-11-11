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

GameManager::~GameManager() {
  delete whiteBall;
  whiteBall = nullptr;
  
  for (int i=0; i<sizeof(balls)/sizeof(balls[0]); i++) {
    delete balls[i];
    balls[i] = nullptr;
  }
}

void GameManager::initialize() {
  // set background color
  glClearColor(0.5f, 0.5f, 0.5f, 0.0f);
}

void GameManager::awake() {
  mainCamera = (PerspectiveCameraController*)(CameraManager::instance()).getMainCamera();
  cameraDefaultPosition = mainCamera->getPosition();
  
  whiteBall = new WhiteBallController(Transform::identity());
  (ObjectManager::instance()).registerObject(whiteBall);
  whiteBall->translateTo(Vector3D::back()*30.0f);
  
  for (int i=0; i<sizeof(balls)/sizeof(balls[0]); i++) {
    balls[i] = new BallController(Transform::identity(), i+1);
    (ObjectManager::instance()).registerObject(balls[i]);

    float row = ceilf((sqrtf(1.0 + 8.0*(i+1)) - 1.0f) / 2.0f);
    int sumAtLastRow = (int)((row*(row-1))/2.0f);
    float posX = 1.1f * (2.0f*((i+1)-sumAtLastRow)-row-1);
    float posZ = (row-1) * 1.75033f * 1.1f;
    balls[i]->translateTo(Vector3D(posX, 0.0f, -posZ));
    balls[i]->rotation(Quaternion(Vector3D(1.0f, 0.0f, 0.0f).normalize(), -M_PI/2.0f));
  }
}

void GameManager::start() {
  whiteBall->addForce(30.0f, Vector3D::forward());
}


void GameManager::update(GLfloat deltaTime) {
//  mainCamera->translateTo(cameraDefaultPosition + Vector3D::forward() * sinf(glfwGetTime() * 3.0f));
}

NS_END
