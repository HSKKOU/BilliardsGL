//
//  GameManager.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/15.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef GameManager_hpp
#define GameManager_hpp

#include "GlobalHeader.h"
#include "Singleton.h"

#include "Window.hpp"
#include "FPSCounter.hpp"

#include "Square.hpp"

#include "Matrix.h"
#include "Cube.hpp"

#include "ObjectManager.hpp"
#include "LightManager.hpp"

#include "Camera.h"

#include "TextureLoader.hpp"

class GameManager : public Singleton<GameManager> {
  friend class Singleton<GameManager>;
  
  Window *window;
  
  LightManager &lightManager;
  CameraManager &cameraManager;
  ObjectManager &objectManager;
  
  FPSCounter &fps;
  
  // for Debug
  BaseObject3D *object;
  BaseObject3D *object2;
  BaseObject3D *object3;
  
public:
  virtual ~GameManager();
  void initialize();
  void startMainLoop();
  
private:
  GameManager();
  void mainLoop();
};

#endif /* GameManager_hpp */
