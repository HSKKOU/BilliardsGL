//
//  BaseRigidObject3D.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/31.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "BaseRigidObject3D.hpp"
#include "CollisionCalculator.hpp"

#include "Constants.h"

NS_ENGINE

BaseRigidObject3D::BaseRigidObject3D(Transform t, RigidBody rig, Surface surf)
: Engine::BaseObject3D(t, surf)
, rigidBody(rig)
{ /* do nothing */ }

BaseRigidObject3D::~BaseRigidObject3D() {
  delete rigidBody.collider;
  rigidBody.collider = nullptr;
}


GLfloat BaseRigidObject3D::getMass() const { return rigidBody.mass; }
Vector3D BaseRigidObject3D::getVelocity() const { return rigidBody.velocity; }
ColliderBase3D* BaseRigidObject3D::getCollider3D() const { return rigidBody.collider; }


bool BaseRigidObject3D::isRigid() const { return true; }
bool BaseRigidObject3D::isCollidable() const { return true; }

void BaseRigidObject3D::updatePhysics(GLfloat deltaTime) {
  // TODO: update Physics transform
  translate(rigidBody.velocity * deltaTime);
  rigidBody.velocity = rigidBody.velocity * Const::DEC_VELOCITY_RATE;
  if (rigidBody.velocity.squareLength() <= Const::VELOCITY_EPS) { rigidBody.velocity = Vector3D::zero(); }
}


void BaseRigidObject3D::addForce(float power, Vector3D dir) {
  rigidBody.velocity += dir.normalize() * power / rigidBody.mass;
}


bool BaseRigidObject3D::isCollideWith(BaseRigidObject3D* other) {
  return CollisionCalculator::isCollided(this, other);
}

void BaseRigidObject3D::onCollisionEnter(BaseRigidObject3D* object) { /* do nothing */ }
void BaseRigidObject3D::onCollisionStay(BaseRigidObject3D* object) { /* do nothing */ }
void BaseRigidObject3D::onCollisionExit(BaseRigidObject3D* object) { /* do nothing */ }

NS_END
