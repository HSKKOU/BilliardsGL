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

GameManager::~GameManager() {
  delete window;
  window = nullptr;
}

void GameManager::initialize() {
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
  glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
  
  // FPS initialize
  fps.initialize(glfwGetTime());

  // Managers initialize
  lightManager.initialize();
  cameraManager.initialize();
  objectManager.initialize();
}

void GameManager::startMainLoop() {
  // initialize TextureLoader
  TextureLoader &textureLoader = TextureLoader::instance();
  textureLoader.initialize();
  
  // set main camera
  CameraController *mainCamera = new CameraController(Vector3D(0.0f,4.0f,10.0f), Vector3D(0.0f,0.0f,0.0f), Vector3D(0.0f,1.0f,0.0f));
  mainCamera->setPerspective(45.0f, 1.0f, 0.5f, 100.0f);
  cameraManager.addCamera(mainCamera);
  
  
  // set main light
  LightControllerBase *light0 = new DirectionalLightController
  (
   Vector3D(0.0f, 3.0f, 0.0f),
   Vector3D::one(),
   Vector3D::one(),
   Vector3D::one()*0.25f,
   Vector3D::one(),
   Vector4D::one()
  );
  lightManager.addLight(light0);

  
  // for Debug create objects
  object = objectManager.instantiateObject(ObjectType::CUBE);
  object->loadShaderProgram("LightTest.vert", "LightTest.frag");
  object->setTexture(Tex::Stone);
  
  object2 = objectManager.instantiateObject(ObjectType::CUBE);
  object2->loadShaderProgram("LightTest.vert", "LightTest.frag");
  object2->setTexture(Tex::Stone);

  object3 = objectManager.instantiateObject(ObjectType::SPHERE);
  object3->loadShaderProgram("LightTest.vert", "LightTest.frag");
  object3->setTexture(Tex::Color4);
  object3->setObjectColor(Color::one());
  
  // game loop
  while (window->shouldClose() == GL_FALSE) {
    fps.update(glfwGetTime());
    mainLoop();
  }
}


void GameManager::mainLoop() {
  // clear buffer,  enable "DEPTH_BUFFER, CULL_FACE"
  window->resetWindow();
  
  // Managers update
  lightManager.updateLights();
  
  object->translate(Vector3D::right() * glfwGetTime());
  object->rotate(Quaternion((Vector3D(1.0f, 0.0f, 0.0f)).normalize(), glfwGetTime()));
  GLfloat scl = sinf(glfwGetTime()*2.0f) / 4.0f + 0.75f;
  object->scale(Vector3D(scl, scl, scl));

  object2->translate(Vector3D::left() * glfwGetTime());
  object2->rotate(Quaternion((Vector3D(0.0f, 1.0f, 0.0f)).normalize(), glfwGetTime()));

  object3->translate(Vector3D::up() * sinf(glfwGetTime()));
  
  objectManager.updateObject();

  // finish this frame, change another drawing buffer
  window->swapBuffers();
}
