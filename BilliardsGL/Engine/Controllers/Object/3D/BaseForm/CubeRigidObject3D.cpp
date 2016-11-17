//
//  CubeRigidObject3D.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/13.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "CubeRigidObject3D.hpp"

NS_ENGINE

CubeRigidObject3D::CubeRigidObject3D(Transform t, Vector3D s, RigidBody rig, Surface surf)
: Engine::BaseRigidObject3D(t, rig, surf)
, size(s)
{ /* do nothing */ }

CubeRigidObject3D::~CubeRigidObject3D() { /* do nothing */ }

void CubeRigidObject3D::setSize(Vector3D s) { size = s; }
Vector3D CubeRigidObject3D::getSize() const { return size; }

void CubeRigidObject3D::updatePhysics(GLfloat deltaTime) {
  BaseRigidObject3D::updatePhysics(deltaTime);
  if (rigidBody.velocity == Vector3D::zero()) { return; }
  // TODO: calc rolling
}

BaseModel3D* CubeRigidObject3D::createModel() { return ModelFactory::createCubeModel(size); }

NS_END
