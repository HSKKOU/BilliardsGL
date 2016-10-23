//
//  ModelFactory.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/07.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "ModelFactory.hpp"

NS_ENGINE_MODEL

BaseModel3D* ModelFactory::instantiateModel(const ModelType type) {
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

NS_END2
