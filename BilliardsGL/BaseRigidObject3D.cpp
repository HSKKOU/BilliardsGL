//
//  BaseRigidObject3D.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/31.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "BaseRigidObject3D.hpp"

NS_ENGINE

BaseRigidObject3D::BaseRigidObject3D(Transform t, GLfloat mass, ColliderBase3D* col)
: Engine::BaseObject3D(t)
, collider(col)
, mass(mass)
, velocity(Vector3D::zero())
{ /* do nothing */ }

BaseRigidObject3D::~BaseRigidObject3D() {
  delete collider;
  collider = nullptr;
}


ColliderBase3D* BaseRigidObject3D::getCollider3D() const { return collider; }


void BaseRigidObject3D::updatePhysics(GLfloat deltaTime) {
  // TODO: update Physics transform
  translate(velocity * deltaTime);
}


void BaseRigidObject3D::addForce(float power, Vector3D dir) {
  velocity = dir.normalize() * power / mass;
}


void BaseRigidObject3D::onCollisionEnter(BaseRigidObject3D* object) { /* do nothing */ }
void BaseRigidObject3D::onCollisionStay(BaseRigidObject3D* object) { /* do nothing */ }
void BaseRigidObject3D::onCollisionExit(BaseRigidObject3D* object) { /* do nothing */ }

NS_END
