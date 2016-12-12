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
: fps(&(FPSCounter::instance()))
{
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
  fps->setShowFlag(
//    true
    false
  );
  fps->start(glfwGetTime());
  
  // Managers instantiate
  CameraManager::instance();
  LightManager::instance();
  ObjectManager::instance();
  SceneManager::instance();
  InputManager &inputManager = InputManager::instance();
  UIManager &uiManager = UIManager::instance();
  
  // set input delegates
  window->setInputManagerDelegate(&inputManager);
  inputManager.setUIManagerDelegate(&uiManager);
}

GameEngineManager::~GameEngineManager() { /* do nothing */ }

void GameEngineManager::startMainLoop() {
  // instantiate TextureLoader
  TextureLoader::instance();
  
  // Initialize main camera
  PerspectiveCameraController *mainCamera
  = new PerspectiveCameraController(
    Transform(
      Vector3D(0.0f,55.0f,0.0f),
      Quaternion(Vector3D::right(), M_PI/2.0f)
    )
  );
  mainCamera->setPerspective(60.0f, 1.0f, 0.5f, 300.0f);
  (CameraManager::instance()).addCamera(mainCamera);
  
  
  // Initialize main light
  SpotLightController *light0 = new SpotLightController(Vector3D(0.0f, 150.0f, 0.0f));
  light0->setPerspective(45.0f, 1.0f, 2.0f, 300.0f);
  (LightManager::instance()).addLight(light0);
  
  
  // start first scene
  (SceneManager::instance()).startFirstScene();

  // wait for fps stable
  while (!fps->isStable()) {
    fps->update(glfwGetTime());
    window->resetWindow();
    window->swapBuffers();
  }
  
  // game loop
  while (window->shouldClose() == GL_FALSE) { mainLoop(); }
}


void GameEngineManager::mainLoop() {
  double deltaTime = fps->update(glfwGetTime());

  // clear buffer,  enable "DEPTH_BUFFER, CULL_FACE"
  window->resetWindow();

  (SceneManager::instance()).updateScene(deltaTime);

  // finish this frame, change another drawing buffer
  window->swapBuffers();
}

NS_END
