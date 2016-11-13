//
//  GameEngineManager.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/20.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef GameEngineManager_hpp
#define GameEngineManager_hpp

#include "Singleton.h"

#include "Window.hpp"
#include "FPSCounter.hpp"

#include "Matrix.h"

#include "ObjectManager.hpp"
#include "LightManager.hpp"
#include "SceneManager.hpp"

#include "InputManager.hpp"

#include "Camera.h"

#include "TextureLoader.hpp"

NS_ENGINE

class GameEngineManager : public Singleton<GameEngineManager> {
  friend class Singleton<GameEngineManager>;
  
  Window *window;
  
  SceneManager &sceneManager;
  LightManager &lightManager;
  CameraManager &cameraManager;
  ObjectManager &objectManager;
  
  InputManager &inputManager;
  
  FPSCounter &fps;

public:
  virtual ~GameEngineManager();
  void initialize();
  void startMainLoop();
  
private:
  GameEngineManager();
  void mainLoop();
};

NS_END

#endif /* GameEngineManager_hpp */
