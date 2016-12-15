//
//  BallManager.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/14.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef BallManager_hpp
#define BallManager_hpp

#include "BehaviorSingleton.h"

#include <vector>

#include "BallController.hpp"
#include "WhiteBallController.hpp"

#include "ObjectManager.hpp"

US_NS_ENGINE_UTIL

NS_GAME

class BallManager : public BehaviorSingleton<BallManager> {
  friend class BehaviorSingleton<BallManager>;
  
  std::vector<BallController*> ballList;
  WhiteBallController* whiteBall;
  
  // for Debug
  static const int BALL_NUM = 15;
  bool isStoppingAllBalls;
  bool isHaveShot;
  
public:
  ~BallManager();
  void initialize();
  
  void awake();
  virtual void update(GLfloat deltaTime);
  
  Vector3D getWhiteBallPos() const;
  void shotWhiteBall();
  
private:
  BallManager();
};

NS_END

#endif /* BallManager_hpp */
