//
//  WhiteBallController.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/23.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef WhiteBallController_hpp
#define WhiteBallController_hpp

#include "BallController.hpp"

US_NS_ENGINE
US_NS_ENGINE_MODEL

NS_GAME

class WhiteBallController : public BallController {
  
public:
  WhiteBallController(Transform t);
  ~WhiteBallController();
  
  void virtual awake();
};

NS_END

#endif /* WhiteBallController_hpp */
