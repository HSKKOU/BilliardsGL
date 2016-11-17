//
//  BaseObject3D.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/22.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "BaseObject3D.hpp"

NS_ENGINE

BaseObject3D::BaseObject3D()
: BaseObject3D(Transform(Vector3D::zero(), Quaternion::one(), Vector3D::one()), Surface())
{ /* do nothing */ }
BaseObject3D::BaseObject3D(Transform t, Surface surf)
: Engine::Base3D(t)
, surface(surf)
{ /* do nothing */ }

BaseObject3D::~BaseObject3D() {
  for (BaseModel3D* model : modelList) { delete model; model = nullptr; }
  modelList.clear();
}

void BaseObject3D::awake() {
  ObjectBehavior::awake();
  createModelWithSetSurface();
}
void BaseObject3D::start() { ObjectBehavior::start(); }
void BaseObject3D::update(GLfloat deltaTime) { ObjectBehavior::update(deltaTime); }
void BaseObject3D::lateUpdate(GLfloat deltaTime) { ObjectBehavior::lateUpdate(deltaTime); }
void BaseObject3D::draw() {
  ObjectBehavior::draw();
  for (BaseModel3D* model : modelList) { model->draw(); }
}
void BaseObject3D::destroy() { ObjectBehavior::destroy(); }


void BaseObject3D::setTransform(Engine::Transform trsf) {
  Base3D::setTransform(trsf);
  for (BaseModel3D* model : modelList) { model->setTransform(trsf); }
}
void BaseObject3D::setColor(Color c) { surface.color = c; }
Color BaseObject3D::getColor() const { return surface.color; }


void BaseObject3D::translateTo(Vector3D dest) {
  Base3D::translateTo(dest);
  for (BaseModel3D* model : modelList) { model->translateTo(dest); }
}
void BaseObject3D::rotation(Quaternion rot) {
  Base3D::rotation(rot);
  for (BaseModel3D* model : modelList) { model->rotation(rot); }
}
void BaseObject3D::scale(Vector3D scl) {
  Base3D::scale(scl);
  for (BaseModel3D* model : modelList) { model->scale(scl); }
}

void BaseObject3D::translate(Vector3D delta) {
  Base3D::translate(delta);
  for (BaseModel3D* model : modelList) { model->translate(delta); }
}
void BaseObject3D::rotate(Quaternion rot) {
  Base3D::rotate(rot);
  for (BaseModel3D* model : modelList) { model->rotate(rot); }
}



BaseModel3D* BaseObject3D::createModelWithSetSurface() {
  BaseModel3D* model = createModel();
  model->setTransform(transform);
  model->loadShaderProgram(surface.shaders.vert, surface.shaders.frag);
  model->setTexture(surface.texture);
  model->setObjectColor(surface.color);
  modelList.emplace_back(model);
  return model;
}

NS_END
