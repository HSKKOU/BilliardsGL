//
//  BallController.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/23.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef BallController_hpp
#define BallController_hpp

#include "BaseObject3D.hpp"

US_NS_ENGINE

NS_GAME

class BallController : public BaseObject3D {
  
public:
  BallController(Transform t);
  virtual ~BallController();
  
  void virtual awake();
  void virtual start();
  void virtual update();
};

NS_END

#endif /* BallController_hpp */