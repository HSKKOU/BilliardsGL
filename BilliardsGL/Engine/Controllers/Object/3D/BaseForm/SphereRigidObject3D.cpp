//
//  SphereRigidObject3D.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/12.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "SphereRigidObject3D.hpp"

NS_ENGINE

SphereRigidObject3D::SphereRigidObject3D(Transform t, GLfloat mass, GLfloat r)
: Engine::BaseRigidObject3D(t, mass, new SphereCollider(r))
, radius(r)
{ /* do nothing */ }

SphereRigidObject3D::~SphereRigidObject3D() { /* do nothing */ }


void SphereRigidObject3D::createSphereModel(ETex tex, Color c) {
  Sphere* sphereModel = ModelFactory::createSphereModel(radius);
  sphereModel->loadShaderProgram("Shaders/Project/test/LightTest.vert", "Shaders/Project/test/LightTest.frag");
  sphereModel->setTexture(tex);
  sphereModel->setObjectColor(c);
  modelList.emplace_back(sphereModel);
}

void SphereRigidObject3D::updatePhysics(GLfloat deltaTime) {
  BaseRigidObject3D::updatePhysics(deltaTime);
  if (velocity == Vector3D::zero()) { return; }
  Vector3D rotationAxis = velocity.cross(Vector3D::down()).normalize();
  GLfloat rotationAng = velocity.length()*deltaTime / (1.9f*M_PI*radius);
  rotate(Quaternion(rotationAxis, rotationAng));
}

NS_END
