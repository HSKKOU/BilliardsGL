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
  bool isCollided = false;
  
  ColliderBase3D* col1 = obj1->getCollider3D();
  ColliderBase3D* col2 = obj2->getCollider3D();
  
  COL_MASK col1Mask = col1->getColliderType();
  COL_MASK col2Mask = col2->getColliderType();
  
  if (col1Mask == COL_TYPE::NONE || col2Mask == COL_TYPE::NONE) {
    return false;
  }
  
  COL_MASK colliderMask = col1Mask | col2Mask;
  
  switch(colliderMask) {
    case COL_TYPE::SPHERE:
      isCollided = isCollidedBetweenSphere(static_cast<SphereCollider*>(col1), static_cast<SphereCollider*>(col2), obj1->getPosition() - obj2->getPosition());
      break;
    case COL_TYPE::CUBE:
      break;
    case COL_TYPE::SPHERE | COL_TYPE::CUBE:
      break;
    default:
      break;
  }
  
  return isCollided;
}

bool CollisionCalculator::isCollidedBetweenSphere(SphereCollider* col1, SphereCollider* col2, Vector3D objectCenterGap) {
  GLfloat objectCenterDist = (col1->getPosition() - col2->getPosition() - objectCenterGap).length();
  GLfloat objectDist = objectCenterDist - (col1->getRadius() + col2->getRadius());
  return objectDist <= COL_DETECT_EPS;
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

NS_END
