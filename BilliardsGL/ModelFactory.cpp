//
//  ModelFactory.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/07.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "ModelFactory.hpp"

NS_ENGINE_MODEL

BaseModel3D* ModelFactory::instantiateSimpleModel(const ModelType type) {
  BaseModel3D *model = nullptr;
  switch (type) {
    case CUBE:
      model = new Cube(Vector3D::zero(), Vector3D::one());
      break;
    case SPHERE:
      model = new Sphere(Vector3D::zero(), 1.0f, 100, 50);
    default:
      break;
  }
  return model;
}

Sphere* ModelFactory::createSphereModel(const GLfloat radius) {
  return new Sphere(Vector3D::zero(), radius, 100, 50);
}

Cube* ModelFactory::createCubeModel(const Vector3D size) {
  return new Cube(Vector3D::zero(), size);
}

NS_END2
