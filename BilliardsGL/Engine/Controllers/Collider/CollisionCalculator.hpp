//
//  CollisionCalculator.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/09.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef CollisionCalculator_hpp
#define CollisionCalculator_hpp

#include "Objects.h"

NS_ENGINE

class CollisionCalculator {
  constexpr static const GLfloat COL_DETECT_EPS = 0.0f;
  constexpr static const GLfloat COL_SPRING_CST = 23.0f;
  
public:
  static bool isCollided(ColliderBase3D* col1, ColliderBase3D* col2);
  static bool isCollidedBetweenSphere(SphereCollider* col1, SphereCollider* col2);
  
  static void calcCollidedVelocityBetweenSphere(BaseRigidObject3D* obj1, BaseRigidObject3D* obj2);
};

NS_END

#endif /* CollisionCalculator_hpp */
