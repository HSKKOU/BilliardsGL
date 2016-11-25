//
//  CollisionCalculator.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/09.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "CollisionCalculator.hpp"

NS_ENGINE

bool CollisionCalculator::isCollided(BaseRigidObject3D* obj1, BaseRigidObject3D* obj2) {
  COL_MASK col1Mask = obj1->getCollider3D()->getColliderType();
  COL_MASK col2Mask = obj2->getCollider3D()->getColliderType();
  
  COL_MASK colsMask = col1Mask | col2Mask;

  switch(colsMask) {
    case COL_TYPE::SPHERE | COL_TYPE::CUBE:
      if (col1Mask == COL_TYPE::SPHERE) {
        return isCollidedBetweenSphereAndCube(static_cast<SphereRigidObject3D*>(obj1), static_cast<CubeRigidObject3D*>(obj2));
      } else {
        return isCollidedBetweenSphereAndCube(static_cast<SphereRigidObject3D*>(obj2), static_cast<CubeRigidObject3D*>(obj1));
      }
      break;
    case COL_TYPE::SPHERE:
      return isCollidedBetweenSphere(static_cast<SphereRigidObject3D*>(obj1), static_cast<SphereRigidObject3D*>(obj2));
    case COL_TYPE::CUBE:
      return false;
    default:
      return false;
  }
}


bool CollisionCalculator::isCollidedBetweenSphereAndCube(SphereRigidObject3D* sRig, CubeRigidObject3D* cRig) {
  return cRig->isCollidedWithSphere(sRig);
}
bool CollisionCalculator::isCollidedBetweenSphere(SphereRigidObject3D* rig1, SphereRigidObject3D* rig2) {
  Vector3D objectCenterDistVec
  = (rig1->getPosition() + rig1->getCollider3D()->getPosition()) - (rig2->getPosition() + rig2->getCollider3D()->getPosition());
  GLfloat objectDist = objectCenterDistVec.length() - (rig1->getCollider3D()->getRadius() + rig2->getCollider3D()->getRadius());
  return objectDist <= COL_DETECT_EPS;
}
bool CollisionCalculator::isCollidedBetweenCube(CubeRigidObject3D* rig1, CubeRigidObject3D* rig2) {
  // TODO:
  return false;
}



void CollisionCalculator::calcCollidedVelocityBetweenSphere(BaseRigidObject3D* obj1, BaseRigidObject3D* obj2) {  
  Vector3D collisionAxis =
  obj1->getPosition() + obj1->getCollider3D()->getPosition()
  - obj2->getPosition() + obj2->getCollider3D()->getPosition();
  
  GLfloat dentLength =
  ((SphereCollider*)obj1->getCollider3D())->getRadius()
  + ((SphereCollider*)obj2->getCollider3D())->getRadius()
  - collisionAxis.length();
  
  obj1->addForce(COL_SPRING_CST*dentLength, collisionAxis.normalize());
  obj2->addForce(COL_SPRING_CST*dentLength, collisionAxis.normalize()*-1.0f);
}







/* Cube Collision Detectors */
bool CollisionCalculator::isCollidedWithSphereByFloor(SphereRigidObject3D* sRig, CubeRigidObject3D* cRig) {
  return false;
}
bool CollisionCalculator::isCollidedWithSphereByAABBCube(SphereRigidObject3D* sRig, CubeRigidObject3D* cRig) {
  return false;
}
bool CollisionCalculator::isCollidedWithSphereByOBBCube(SphereRigidObject3D* sRig, CubeRigidObject3D* cRig) {
  return false;
}


NS_END
