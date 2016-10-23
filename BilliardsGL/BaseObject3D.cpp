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

void BaseObject3D::addObject(BaseObject3D* object) { childrenList.emplace_back(object); }
BaseObject3D* BaseObject3D::getObject(int index) const {
  if (index < 0 || index >= childrenList.size()) { return nullptr; }
  return childrenList.at(index);
}
void BaseObject3D::removeObject(int index) {
  if (index < 0 || index >= childrenList.size()) { return; }
  childrenList.erase(childrenList.begin() + index);
}

void BaseObject3D::awake() {
  for (BaseObject3D* obj : childrenList) { obj->awake(); }
}
void BaseObject3D::start() {
  for (BaseObject3D* obj : childrenList) { obj->start(); }
}
void BaseObject3D::update() {
  for (BaseObject3D* obj : childrenList) { obj->update(); }
}
void BaseObject3D::lateUpdate() {
  for (BaseObject3D* obj : childrenList) { obj->lateUpdate(); }
}

NS_END
