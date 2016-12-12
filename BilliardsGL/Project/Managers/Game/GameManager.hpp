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
#include "UI.h"

US_NS_ENGINE
US_NS_ENGINE_MODEL
US_NS_ENGINE_UI

NS_GAME

class GameManager : public BehaviorSingleton<GameManager>, public IButtonHandler {
  friend class BehaviorSingleton<GameManager>;
  
  BallManager* ballManager;
  BoardController* boardCtrl;
  
  PerspectiveCameraController* mainCamera;
  Vector3D cameraDefaultPosition;
  
  UIButton* shotButton;
  
public:
  ~GameManager();
  void initialize();
  
  virtual void awake();
  virtual void start();
  virtual void update(GLfloat deltaTime);
  
  virtual void destroy();
  
private:
  GameManager();

  void onButtonDown();
  void onButtonDownRepeat();
  void onButtonUp();

};

NS_END

#endif /* GameManager_hpp */
