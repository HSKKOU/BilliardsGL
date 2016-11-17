//
//  CubeRigidObject3D.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/13.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "CubeRigidObject3D.hpp"

NS_ENGINE

CubeRigidObject3D::CubeRigidObject3D(Transform t, GLfloat mass, Vector3D s)
: Engine::BaseRigidObject3D(t, mass, new CubeCollider(s))
, size(s)
{ /* do nothing */ }

CubeRigidObject3D::~CubeRigidObject3D() { /* do nothing */ }


void CubeRigidObject3D::updatePhysics(GLfloat deltaTime) {
  BaseRigidObject3D::updatePhysics(deltaTime);
  if (velocity == Vector3D::zero()) { return; }
  // TODO: calc rolling
}

Cube* CubeRigidObject3D::createCubeModel(ETex tex, Color c) {
  Cube* cubeModel = ModelFactory::createCubeModel(size);
  cubeModel->loadShaderProgram("Shaders/Project/test/LightTest.vert", "Shaders/Project/test/LightTest.frag");
  cubeModel->setTexture(tex);
  cubeModel->setObjectColor(c);
  modelList.emplace_back(cubeModel);
  return cubeModel;
}

NS_END
