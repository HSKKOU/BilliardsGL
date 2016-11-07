//
//  GameScene.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/20.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef GameScene_hpp
#define GameScene_hpp

#include "SceneBase.hpp"

#include "GameManager.hpp"

US_NS_ENGINE

NS_GAME

class GameScene : public SceneBase {
  GameManager &gameManager;
  
public:
  GameScene();
  virtual ~GameScene();
  
  virtual void enter();
  virtual void exit();
  virtual void update(GLfloat deltaTime);
};

NS_END

#endif /* GameScene_hpp */
