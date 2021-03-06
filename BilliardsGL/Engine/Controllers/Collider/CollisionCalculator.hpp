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
  static bool collideObjects(BaseRigidObject3D* obj1, BaseRigidObject3D* obj2);

  static bool isCollidedBetweenSphereAndCube(SphereRigidObject3D* sRig, CubeRigidObject3D* cRig);
  static bool isCollidedBetweenSphere(SphereRigidObject3D* rig1, SphereRigidObject3D* rig2);
  static bool isCollidedBetweenCube(CubeRigidObject3D* rig1, CubeRigidObject3D* rig2);
  
  static void calcCollidedVelocityBetweenSphere(SphereRigidObject3D* rig1, SphereRigidObject3D* rig2);
  static void calcCollidedVelocityBetweenSphereAndCube(SphereRigidObject3D* sRig, CubeRigidObject3D* cRig);

  static Quad createCollisionPlaneBetweenPointAndCube(Point3D point, Point3D cubeCenter, Vector3D cubeSize);

  
  /* Cube Collision Detectors */
  static bool isCollidedWithSphereByAABBCube(SphereRigidObject3D* sRig, CubeRigidObject3D* cRig);
  static bool isCollidedWithSphereByOBBCube(SphereRigidObject3D* sRig, CubeRigidObject3D* cRig);
};

NS_END

#endif /* CollisionCalculator_hpp */
