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
#include "SceneManager.hpp"

#include "Camera.h"

#include "TextureLoader.hpp"

US_NS_ENGINE

class GameManager : public Singleton<GameManager> {
  friend class Singleton<GameManager>;
  
  // for Debug
  BaseObject3D* balls[16];
  
public:
  virtual ~GameManager();
  void initialize();
  void startMainLoop();
  
private:
  GameManager();
  void mainLoop();
};

#endif /* GameManager_hpp */
