//
//  BallManager.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/14.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef BallManager_hpp
#define BallManager_hpp

#include "Singleton.h"

#include <vector>

#include "BallController.hpp"
#include "WhiteBallController.hpp"

#include "ObjectManager.hpp"

US_NS_ENGINE_UTIL

NS_GAME

class BallManager : public Singleton<BallManager> {
  friend class Singleton<BallManager>;
  
  std::vector<BallController*> ballList;
  WhiteBallController* whiteBall;
  
  // for Debug
  static const int BALL_NUM = 15;
  
public:
  ~BallManager();
  void initialize();
  
  void shotWhiteBall();
  
private:
  BallManager();
};

NS_END

#endif /* BallManager_hpp */
