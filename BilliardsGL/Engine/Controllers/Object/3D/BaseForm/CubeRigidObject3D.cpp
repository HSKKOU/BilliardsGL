//
//  CubeRigidObject3D.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/13.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "CubeRigidObject3D.hpp"
#include "CollisionCalculator.hpp"

NS_ENGINE

CubeRigidObject3D::CubeRigidObject3D(Transform t, Vector3D s, RigidBody rig, CubeCollider* col, Surface surf)
: Engine::BaseRigidObject3D(t, rig, col, surf)
, size(s)
{ /* do nothing */ }
CubeRigidObject3D::CubeRigidObject3D(Transform t, Vector3D s, RigidBody rig, Surface surf)
: Engine::BaseRigidObject3D(t, rig, new CubeCollider(Transform::identity(), s), surf)
, size(s)
{ /* do nothing */ }

CubeRigidObject3D::~CubeRigidObject3D() { /* do nothing */ }

void CubeRigidObject3D::setSize(Vector3D s) { size = s; }
Vector3D CubeRigidObject3D::getSize() const { return size; }

CubeCollider* CubeRigidObject3D::getCollider3D() const { return static_cast<CubeCollider*>(collider); }

void CubeRigidObject3D::updatePhysics(GLfloat deltaTime) {
  BaseRigidObject3D::updatePhysics(deltaTime);
  if (rigidBody.velocity == Vector3D::zero()) { return; }
  // TODO: calc rolling
}

bool CubeRigidObject3D::isCollidedWithSphere(SphereRigidObject3D* sRig) {
  return CollisionCalculator::isCollidedWithSphereByOBBCube(sRig, this);
}


BaseModel3D* CubeRigidObject3D::createModel() { return ModelFactory::createCubeModel(size); }

NS_END
