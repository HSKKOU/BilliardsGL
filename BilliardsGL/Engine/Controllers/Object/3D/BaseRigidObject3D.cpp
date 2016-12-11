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

BaseRigidObject3D::BaseRigidObject3D(Transform t, RigidBody rig, ColliderBase3D* col, Surface surf)
: Engine::BaseObject3D(t, surf)
, rigidBody(rig)
, collider(col)
, isStaticFlag(false)
, isRefGravityFlag(false)
{ /* do nothing */ }

BaseRigidObject3D::~BaseRigidObject3D() { SAFE_DELETE(collider); }


GLfloat BaseRigidObject3D::getMass() const { return rigidBody.mass; }
Vector3D BaseRigidObject3D::getVelocity() const { return rigidBody.velocity; }
ColliderBase3D* BaseRigidObject3D::getCollider3D() const { return collider; }


bool BaseRigidObject3D::isStatic() const { return isStaticFlag; }
bool BaseRigidObject3D::isRigid() const { return true; }
bool BaseRigidObject3D::isCollidable() const { return true; }
bool BaseRigidObject3D::isRefGravity() const { return isRefGravityFlag; }

void BaseRigidObject3D::setIsStatic(bool flag) { isStaticFlag = flag; }
void BaseRigidObject3D::setRefGravity(const bool flag) { isRefGravityFlag = flag; }


void BaseRigidObject3D::updatePhysics(GLfloat deltaTime) {
  if (isStatic()) { return; }
  translate(rigidBody.velocity * deltaTime);
  rigidBody.velocity = rigidBody.velocity * Const::DEC_VELOCITY_RATE;
  
  if (isRefGravityFlag) { rigidBody.velocity += Vector3D::down() * Const::GRAVITY_ACCEL * deltaTime; }
  
  if (rigidBody.velocity.squareLength() <= Const::VELOCITY_EPS) { rigidBody.velocity = Vector3D::zero(); }
}


void BaseRigidObject3D::addForce(const float power, Vector3D dir) {
  rigidBody.velocity += dir.normalize() * power / rigidBody.mass;
}


void BaseRigidObject3D::onCollisionEnter(BaseRigidObject3D* object) { /* do nothing */ }
void BaseRigidObject3D::onCollisionStay(BaseRigidObject3D* object) { /* do nothing */ }
void BaseRigidObject3D::onCollisionExit(BaseRigidObject3D* object) { /* do nothing */ }

NS_END
