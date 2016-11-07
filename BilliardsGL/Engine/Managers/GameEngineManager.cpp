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
  window = new Window(640, 640, "BilliardGL");
  
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
}

void GameEngineManager::startMainLoop() {
  // initialize TextureLoader
  TextureLoader &textureLoader = TextureLoader::instance();
  textureLoader.initialize();
  
  // set main camera
  PerspectiveCameraController *mainCamera
  = new PerspectiveCameraController(
    Transform(
      Vector3D(0.0f,30.0f,0.0f),
      Quaternion(Vector3D::right(), M_PI/2.0f)
    )
  );
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
  
  
  // game loop
  sceneManager.switchSceneTo(0);
  bool waitStable = true;
  while (window->shouldClose() == GL_FALSE) {
    double deltaTime = fps.update(glfwGetTime());
   
    // clear buffer,  enable "DEPTH_BUFFER, CULL_FACE"
    window->resetWindow();
    
    if (!waitStable) {
      mainLoop(deltaTime);
    }
    
    // finish this frame, change another drawing buffer
    window->swapBuffers();

    if (std::abs(fps.getFPS()-60.0) < 5.0) { waitStable = false; }
  }
}


void GameEngineManager::mainLoop(GLfloat deltaTime) {
  sceneManager.updateScene(deltaTime);
}

NS_END