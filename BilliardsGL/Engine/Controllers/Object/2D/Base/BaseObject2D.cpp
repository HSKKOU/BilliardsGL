//
//  BaseObject2D.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/11.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "BaseObject2D.hpp"

NS_ENGINE

BaseObject2D::BaseObject2D() : BaseObject2D(Point2D::zero()) { /* do nothing */ }
BaseObject2D::BaseObject2D(Point2D p) : Engine::Base2D(p) { for (BaseModel2D* model : modelList) { model->setPosition(p); } }

BaseObject2D::~BaseObject2D() { SAFE_DELETE_VECTOR(modelList, BaseModel2D); }

void BaseObject2D::awake() { ObjectBehavior::awake(); }
void BaseObject2D::start() { ObjectBehavior::start(); }
void BaseObject2D::update(GLfloat deltaTime) { ObjectBehavior::update(deltaTime); }
void BaseObject2D::lateUpdate(GLfloat deltaTime) { ObjectBehavior::lateUpdate(deltaTime); }
void BaseObject2D::draw() {
  ObjectBehavior::draw();
  for (BaseModel2D* model : modelList) { model->draw(); }
}
void BaseObject2D::destroy() { ObjectBehavior::destroy(); }

NS_END
