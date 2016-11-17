//
//  GameEngineManager.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/20.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "GameEngineManager.hpp"

NS_ENGINE

GameEngineManager::GameEngineManager()
: sceneManager(SceneManager::instance())
, lightManager(LightManager::instance())
, cameraManager(CameraManager::instance())
, objectManager(ObjectManager::instance())
, inputManager(InputManager::instance())
, uiManager(UIManager::instance())
, fps(FPSCounter::instance())
{ /* do nothing */ }

GameEngineManager::~GameEngineManager() { /* do nothing */ }

void GameEngineManager::initialize() {
  // initialize GLFW
  if (glfwInit() == GL_FALSE) {
    std::cerr << "Can't initialize GLFW" << std::endl;
    exit(1);
  }
  
  // register operation terminated program
  atexit(glfwTerminate);
  
  // select OpenGL Version 4.1 Core Profile
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  
  // create window
  window = new Window();
  
  // set background color
  glClearColor(0.5f, 0.5f, 0.5f, 0.0f);
  
  // FPS initialize
  fps.initialize(glfwGetTime()
//                 , true
                 , false
                 );
  
  // Managers initialize
  objectManager.initialize();
  sceneManager.initialize();
  lightManager.initialize();
  cameraManager.initialize();
  inputManager.initialize();
  uiManager.initialize();
  
  window->setInputManagerDelegate(&inputManager);
  inputManager.setUIManagerDelegate(&uiManager);
}

void GameEngineManager::startMainLoop() {
  // initialize TextureLoader
  TextureLoader &textureLoader = TextureLoader::instance();
  textureLoader.initialize();
  
  // set main camera
  PerspectiveCameraController *mainCamera
  = new PerspectiveCameraController(
    Transform(
      Vector3D(0.0f,35.0f,0.0f),
      Quaternion(Vector3D::right(), M_PI/2.0f)
    )
  );
  mainCamera->setPerspective(60.0f, 1.0f, 0.5f, 100.0f);
  cameraManager.addCamera(mainCamera);
  
  
  // set main light
  LightControllerBase *light0 = new SpotLightController(Vector3D(0.0f, 30.0f, 0.0f));
  lightManager.addLight(light0);
  
  
  // start first scene
  sceneManager.startFirstScene();

  // wait for fps stable
  while (!fps.isStable()) {
    fps.update(glfwGetTime());
    window->resetWindow();
    window->swapBuffers();
  }
  
  // game loop
  while (window->shouldClose() == GL_FALSE) { mainLoop(); }
}


void GameEngineManager::mainLoop() {
  double deltaTime = fps.update(glfwGetTime());

  // clear buffer,  enable "DEPTH_BUFFER, CULL_FACE"
  window->resetWindow();

  sceneManager.updateScene(deltaTime);

  // finish this frame, change another drawing buffer
  window->swapBuffers();
}

NS_END
