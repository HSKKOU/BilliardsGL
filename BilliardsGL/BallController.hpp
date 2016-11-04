//
//  BallController.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/23.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef BallController_hpp
#define BallController_hpp

#include "BaseRigidObject3D.hpp"
#include "Collisions.h"

#include "Sphere.hpp"

#include "ModelFactory.hpp"

#include <cmath>

US_NS_ENGINE
US_NS_ENGINE_MODEL

NS_GAME

class BallController : public BaseRigidObject3D {
  int number;
  
public:
  BallController(Transform t);
  BallController(Transform t, int number);
  virtual ~BallController();
  
  void virtual awake();
  void virtual start();
  void virtual update();
  
protected:
  void createBall(Tex texture);
};

NS_END

#endif /* BallController_hpp */
