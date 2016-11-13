//
//  BallController.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/23.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef BallController_hpp
#define BallController_hpp

#include "SphereRigidObject3D.hpp"
#include "Collisions.h"

#include <cmath>

US_NS_ENGINE
US_NS_ENGINE_MODEL

NS_GAME

class BallController : public SphereRigidObject3D {
  int number;
  
public:
  BallController(Transform t);
  BallController(Transform t, int number);
  virtual ~BallController();
  
  void virtual awake();
  
protected:
  void createBall(ETex texture);
};

NS_END

#endif /* BallController_hpp */
