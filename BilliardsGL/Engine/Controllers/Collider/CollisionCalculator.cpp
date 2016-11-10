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
  GLfloat objectCenterDist = (col1->getPosition() - col2->getPosition()).squareLength();
  GLfloat objectDist = objectCenterDist - (col1->getRadius() + col2->getRadius());
  return objectDist <= COL_EPS;
}

void CollisionCalculator::calcCollidedVelocityBetweenSphere(BaseRigidObject3D* obj1, BaseRigidObject3D* obj2) {
  GLfloat mass1 = obj1->getMass();
  GLfloat mass2 = obj2->getMass();
  GLfloat totalMass = mass1 + mass2;
  
  Vector3D vel1 = obj1->getVelocity();
  Vector3D vel2 = obj2->getVelocity();
  
  // for Debug : 反発係数
  GLfloat ref = 1.0f + 0.8f;
  
  Vector3D collisionAxis = (obj2->getCollider3D()->getPosition() - obj1->getCollider3D()->getPosition()).normalize();
  Vector3D collidedVec = collisionAxis * (vel1-vel2).dot(collisionAxis);
  
  obj1->setVelocity(collidedVec * (-mass2 / totalMass) * ref + vel1);
  obj2->setVelocity(collidedVec * (mass1 / totalMass) * ref + vel2);  
}

NS_END
