//
//  BaseObject3D.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/22.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "BaseObject3D.hpp"

NS_ENGINE

BaseObject3D::BaseObject3D() : Engine::Base3D(Transform(Vector3D::zero(), Quaternion::one(), Vector3D::one())) { /* do nothing */ }
BaseObject3D::BaseObject3D(Transform t) : Engine::Base3D(t) { /* do nothing */ }
BaseObject3D::~BaseObject3D() { /* do nothing */ }

void BaseObject3D::addModel(BaseModel3D* model) { modelList.emplace_back(model); }
BaseModel3D* BaseObject3D::getModel(int index) const {
  if (index < 0 || index >= modelList.size()) { return nullptr; }
  return modelList.at(index);
}
void BaseObject3D::removeModel(int index) {
  if (index < 0 || index >= modelList.size()) { return; }
  modelList.erase(modelList.begin() + index);
}

void BaseObject3D::awake() { /* do nothing */ }
void BaseObject3D::start() { /* do nothing */ }
void BaseObject3D::update() { /* do nothing */ }
void BaseObject3D::lateUpdate() { /* do nothing */ }

NS_END
