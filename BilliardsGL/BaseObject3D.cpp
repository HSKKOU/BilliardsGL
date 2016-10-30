//
//  BaseObject3D.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/22.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "BaseObject3D.hpp"

NS_ENGINE

BaseObject3D::BaseObject3D() : BaseObject3D(Transform(Vector3D::zero(), Quaternion::one(), Vector3D::one())) { /* do nothing */ }
BaseObject3D::BaseObject3D(Transform t) : Engine::Base3D(t) { for (BaseModel3D* model : modelList) { model->setTransform(t); } }

BaseObject3D::~BaseObject3D() { /* do nothing */ }

void BaseObject3D::awake() { ObjectBehavior::awake(); }
void BaseObject3D::start() { ObjectBehavior::start(); }
void BaseObject3D::update() { ObjectBehavior::update(); }
void BaseObject3D::lateUpdate() { ObjectBehavior::lateUpdate(); }
void BaseObject3D::draw() {
  ObjectBehavior::draw();
  for (BaseModel3D* model : modelList) { model->draw(); }
}
void BaseObject3D::destroy() { ObjectBehavior::destroy(); }


void BaseObject3D::translate(Vector3D dest) {
  for (BaseModel3D* model : modelList) { model->translate(dest); }
}

void BaseObject3D::rotation(Quaternion rot) {
  for (BaseModel3D* model : modelList) { model->rotation(rot); }
}

void BaseObject3D::scale(Vector3D scl) {
  for (BaseModel3D* model : modelList) { model->scale(scl); }
}

void BaseObject3D::rotate(Quaternion rot) {
  for (BaseModel3D* model : modelList) { model->rotate(rot); }
}


NS_END
