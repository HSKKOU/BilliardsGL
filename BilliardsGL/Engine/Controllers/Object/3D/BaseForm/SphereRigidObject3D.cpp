//
//  SphereRigidObject3D.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/12.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "SphereRigidObject3D.hpp"

NS_ENGINE

SphereRigidObject3D::SphereRigidObject3D(Transform t, GLfloat r, RigidBody rig, SphereCollider* col, Surface surf)
: Engine::BaseRigidObject3D(t, rig, col, surf)
, radius(r)
{ /* do nothing */ }
SphereRigidObject3D::SphereRigidObject3D(Transform t, GLfloat r, RigidBody rig, Surface surf)
: Engine::BaseRigidObject3D(t, rig, new SphereCollider(Transform::identity(), r), surf)
, radius(r)
{ /* do nothing */ }

SphereRigidObject3D::~SphereRigidObject3D() { /* do nothing */ }

void SphereRigidObject3D::setRadius(GLfloat r) { radius = r; }
GLfloat SphereRigidObject3D::getRadius() const { return radius; }

SphereCollider* SphereRigidObject3D::getCollider3D() const { return static_cast<SphereCollider*>(collider); }

void SphereRigidObject3D::updatePhysics(GLfloat deltaTime) {
  BaseRigidObject3D::updatePhysics(deltaTime);
  if (rigidBody.velocity == Vector3D::zero()) { return; }
  Vector3D rotationAxis = rigidBody.velocity.cross(Vector3D::down()).normalize();
  GLfloat rotationAng = rigidBody.velocity.length()*deltaTime / (M_PI*radius);
  rotate(Quaternion(rotationAxis, rotationAng));
}

BaseModel3D* SphereRigidObject3D::createModel() { return ModelFactory::createSphereModel(radius); }

NS_END
