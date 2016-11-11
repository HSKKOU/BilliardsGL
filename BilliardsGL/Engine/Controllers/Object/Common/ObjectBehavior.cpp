//
//  ObjectBehavior.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/23.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "ObjectBehavior.hpp"

NS_ENGINE

ObjectBehavior::ObjectBehavior() { /* do nothing */ }
ObjectBehavior::~ObjectBehavior() { /* do nothing */ }

bool ObjectBehavior::isRigid() const { return false; }
bool ObjectBehavior::isCollidable() const { return false; }

void ObjectBehavior::awake() { /* do nothing */ }
void ObjectBehavior::start() { /* do nothing */ }

void ObjectBehavior::updatePhysics(GLfloat deltaTime) { /* do nothing */ }

void ObjectBehavior::update(GLfloat deltaTime) { /* do nothing */ }
void ObjectBehavior::lateUpdate(GLfloat deltaTime) { /* do nothing */ }

void ObjectBehavior::draw() { /* do nothing */ }

void ObjectBehavior::destroy() { /* do nothing */ }

NS_END
