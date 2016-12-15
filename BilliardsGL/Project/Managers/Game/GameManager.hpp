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

#include "StateMachine.hpp"
#include "State.hpp"

#include "Matrix.h"
#include "Camera.h"
#include "UI.h"

US_NS_ENGINE
US_NS_ENGINE_MODEL
US_NS_ENGINE_UI
US_NS_ENGINE_UTIL

NS_GAME

enum class EGameState {
  Init,
  Shot,
  Roll,
  Num
};

class GameManager : public BehaviorSingleton<GameManager>, public IButtonHandler {
  friend class BehaviorSingleton<GameManager>;
  
  StateMachine<GameManager>* stateMachine;
  
  BallManager* ballManager;
  BoardController* boardCtrl;
  
  PerspectiveCameraController* mainCamera;
  Vector3D cameraDefaultPosition;
  
  UIButton* shotButton;
  
  EGameState currentState;
  
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


  class InitState : public State<GameManager> {
  public:
    InitState(GameManager* _owner);
    ~InitState();
    
    void enter();
    void execute(GLfloat deltaTime);
    void exit();
  };
  
  class ShotState : public State<GameManager> {
  public:
    ShotState(GameManager* _owner);
    ~ShotState();
    
    void enter();
    void execute(GLfloat deltaTime);
    void exit();
  };
  
  class RollState : public State<GameManager> {
  public:
    RollState(GameManager* _owner);
    ~RollState();
    
    void enter();
    void execute(GLfloat deltaTime);
    void exit();
  };
};

NS_END

#endif /* GameManager_hpp */
