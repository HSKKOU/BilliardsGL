//
//  GameManager.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/15.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "GameManager.hpp"

GameManager::GameManager()
: sceneManager(SceneManager::instance())
, lightManager(LightManager::instance())
, cameraManager(CameraManager::instance())
, objectManager(ObjectManager::instance())
, fps(FPSCounter::instance())
{ /* do nothing */ }

GameManager::~GameManager() { /* do nothing */ }

void GameManager::initialize() {
  // set background color
  glClearColor(0.5f, 0.5f, 0.5f, 0.0f);
  
  // FPS initialize
  fps.initialize(glfwGetTime());

  // Managers initialize
  sceneManager.initialize();
  lightManager.initialize();
  cameraManager.initialize();
  objectManager.initialize();
}

void GameManager::startMainLoop() {
  // initialize TextureLoader
  TextureLoader &textureLoader = TextureLoader::instance();
  textureLoader.initialize();
  
  // set main camera
  PerspectiveCameraController *mainCamera = new PerspectiveCameraController(Vector3D(0.0f,30.0f,0.0f), Vector3D(0.0f,0.0f,0.0f), Vector3D(0.0f,0.0f,-1.0f));
  mainCamera->setPerspective(60.0f, 1.0f, 0.5f, 100.0f);
  cameraManager.addCamera(mainCamera);
  
  
  // set main light
  LightControllerBase *light0 = new DirectionalLightController
  (
   Vector3D(0.0f, 10.0f, 0.0f),
   Vector3D::one(),
   Vector3D::one(),
   Vector3D::one()*0.25f,
   Vector3D::one(),
   Vector4D::one()
  );
  lightManager.addLight(light0);

  
  // for Debug create ball objects
  balls[0] = objectManager.instantiateObject(ObjectType::SPHERE);
  balls[0]->loadShaderProgram("LightTest.vert", "LightTest.frag");
  balls[0]->setTexture(Tex::Ball00);
  balls[0]->setObjectColor(Color::one());
  balls[0]->translate(Vector3D(0.0f, 0.0f, 10.0f));
  for (int i=1; i<=15; i++) {
    balls[i] = objectManager.instantiateObject(ObjectType::SPHERE);
    balls[i]->loadShaderProgram("LightTest.vert", "LightTest.frag");
    balls[i]->setTexture(static_cast<Tex>(static_cast<int>(Tex::Ball00)+i));
    balls[i]->setObjectColor(Color::one());
    float row = ceilf((sqrtf(1.0 + 8.0*i) - 1.0f) / 2.0f);
    int sumAtLastRow = (int)((row*(row-1))/2.0f);
    float posX = 1.01f * (2.0f*(i-sumAtLastRow)-row-1);
    float posZ = (row-1) * 1.75033f;
    balls[i]->translate(Vector3D(posX, 0.0f, -posZ));
    balls[i]->rotate(Quaternion(Vector3D(1.0f, 0.0f, 0.0f).normalize(), -M_PI/2.0f));
  }
}


void GameManager::mainLoop() {
  balls[0]->translate(Vector3D(0.0f, 0.0f, 10.0f-sinf(glfwGetTime())*3.0f));
  for (int i=1; i<=15; i++) {
    float row = ceilf((sqrtf(1.0 + 8.0*i) - 1.0f) / 2.0f);
    int sumAtLastRow = (int)((row*(row-1))/2.0f);
    float posX = 1.01f * (2.0f*(i-sumAtLastRow)-row-1);
    float posZ = (row-1) * 1.75033f + sinf(glfwGetTime())*3.0f;
    balls[i]->translate(Vector3D(posX, 0.0f, -posZ));
    balls[i]->rotate(Quaternion(Vector3D(1.0f, 0.0f, 0.0f).normalize(), -M_PI/2.0f));
  }
}
