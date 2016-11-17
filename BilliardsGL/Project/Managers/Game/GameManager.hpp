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
#include "BallManager.hpp"
#include "BoardController.hpp"

#include "Matrix.h"
#include "Camera.h"

US_NS_ENGINE
US_NS_ENGINE_MODEL

NS_GAME

class GameManager : public BehaviorSingleton<GameManager> {
  friend class BehaviorSingleton<GameManager>;
  
  BallManager* ballManager;
  BoardController* boardCtrl;
  
  PerspectiveCameraController* mainCamera;
  Vector3D cameraDefaultPosition;
  
public:
  ~GameManager();
  void initialize();
  
  virtual void awake();
  virtual void start();
  virtual void update(GLfloat deltaTime);
  
  virtual void destroy();
  
private:
  GameManager();
};

NS_END

#endif /* GameManager_hpp */
