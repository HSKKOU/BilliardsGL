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
#include "BehaviorSingleton.h"

#include "ObjectManager.hpp"

#include "Matrix.h"

#include "BallController.hpp"
#include "WhiteBallController.hpp"

#include "Camera.h"

US_NS_ENGINE
US_NS_ENGINE_MODEL

NS_GAME

class GameManager : public BehaviorSingleton<GameManager> {
  friend class BehaviorSingleton<GameManager>;
  
  // for Debug
  BallController* whiteBall;
  BallController* balls[15];
  
  PerspectiveCameraController* mainCamera;
  Vector3D cameraDefaultPosition;
  
public:
  virtual ~GameManager();
  void initialize();
  
  virtual void awake();
  virtual void start();
  virtual void update(GLfloat deltaTime);
  
private:
  GameManager();
};

NS_END

#endif /* GameManager_hpp */