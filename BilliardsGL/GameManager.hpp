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

#include "glm/glm.hpp"
#include "Matrix.h"
#include "Cube.hpp"

#include "LightManager.hpp"

#include "CameraManager.hpp"

class GameManager : public Singleton<GameManager> {
  friend class Singleton<GameManager>;
  
  Window *window;
  
//  Square *square;
  Cube *cube;
  
public:
  void initialize();
  void startMainLoop();
  
private:
  GameManager();
  void mainLoop();
};

#endif /* GameManager_hpp */
