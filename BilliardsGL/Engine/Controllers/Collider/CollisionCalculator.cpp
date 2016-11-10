//
//  CollisionCalculator.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/09.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "CollisionCalculator.hpp"

NS_ENGINE

bool CollisionCalculator::isCollided(ColliderBase3D* col1, ColliderBase3D* col2) {
  // TODO : generalize
  return isCollidedBetweenSphere(static_cast<SphereCollider*>(col1), static_cast<SphereCollider*>(col2));
}

bool CollisionCalculator::isCollidedBetweenSphere(SphereCollider* col1, SphereCollider* col2) {
  GLfloat objectCenterDist = (col1->getPosition() - col2->getPosition()).length();
  GLfloat objectDist = objectCenterDist - (col1->getRadius() + col2->getRadius());
  return objectDist <= COL_EPS;
}

void CollisionCalculator::calcCollidedVelocityBetweenSphere(BaseRigidObject3D* obj1, BaseRigidObject3D* obj2) {
  GLfloat k = 10.0f;
  
  Vector3D collisionAxis = obj1->getCollider3D()->getPosition() - obj2->getCollider3D()->getPosition();
  GLfloat dentLength =
  ((SphereCollider*)obj1->getCollider3D())->getRadius()
  + ((SphereCollider*)obj2->getCollider3D())->getRadius()
  - collisionAxis.length();
  
  obj1->addForce(k*dentLength, collisionAxis.normalize());
  obj2->addForce(k*dentLength, collisionAxis.normalize()*-1.0f);
}

NS_END
