//
//  ObjectManager.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/07.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "ObjectManager.hpp"

NS_ENGINE

ObjectManager::ObjectManager() { /* do nothing */ }
ObjectManager::~ObjectManager() { /* do nothing */ }

// Object Control
ObjectBehavior* ObjectManager::registerObject(ObjectBehavior* object) {
  object->awake();
  awakenObjectList.push_back(object);
  return object;
}

ObjectBehavior* ObjectManager::getObject(const int objectId) const {
  if (objectId < 0 || objectId > objectList.size()) {
    std::cout << "objectId is out of list" << std::endl;
    return nullptr;
  }
  
  for (auto itr = objectList.begin(); itr != objectList.end(); itr++) {
    // TODO: search object
  }
  
  return nullptr;
}

void ObjectManager::destroyObject(const int objectId) const {
  
}



void ObjectManager::startAwakenObjects() {
  for (ObjectBehavior* ob : awakenObjectList) {
    ob->start();
    if (ob->isRigid()) {
      if (!ob->isStatic()) { movableRigidObjectList.push_back(static_cast<BaseRigidObject3D*>(ob)); }
      rigidObjectList.push_back(static_cast<BaseRigidObject3D*>(ob));
    }
    objectList.push_back(ob);
  }
  awakenObjectList.clear();
}

void ObjectManager::updateObjectsPhysics(GLfloat deltaTime) {
  for (int i=0; i<movableRigidObjectList.size(); i++) {
    if (rigidObjectList[i] == nullptr) { continue; }
    rigidObjectList[i]->updatePhysics(deltaTime);
  }
  
  std::vector<BaseRigidObject3D*> collidedObjectList;
  for (int targetIndex=0; targetIndex<movableRigidObjectList.size(); targetIndex++) {
    BaseRigidObject3D* targetObject = rigidObjectList[targetIndex];

    if (targetObject == nullptr) { continue; }
    if (!targetObject->isCollidable()) { continue; }

    for (int otherIndex=targetIndex+1; otherIndex<rigidObjectList.size(); otherIndex++) {
      BaseRigidObject3D* otherObject = rigidObjectList[otherIndex];
      
      if (otherObject == nullptr || otherIndex == targetIndex) { continue; }
      if (!otherObject->isCollidable()) { continue; }
      if (CollisionCalculator::collideObjects(targetObject, otherObject)) { break; }
    }

//    targetObject->translate(targetObject->getVelocity()*deltaTime);
//    collidedObject->translate(collidedObject->getVelocity()*deltaTime);
  }
}

void ObjectManager::updateObjects(GLfloat deltaTime) {
//  std::cout << "objects: " << objectList.size() << std::endl;
  for (int targetIndex=0; targetIndex<objectList.size(); targetIndex++) {
    ObjectBehavior* targetObject = objectList[targetIndex];
    if ( targetObject == nullptr ) { continue; }
    targetObject->update(deltaTime);
  }
}

void ObjectManager::lateUpdateObjects(GLfloat deltaTime) {
  for (int targetIndex=0; targetIndex<objectList.size(); targetIndex++) {
    ObjectBehavior* targetObject = objectList[targetIndex];
    if ( targetObject == nullptr ) { continue; }
    targetObject->lateUpdate(deltaTime);
  }
}

void ObjectManager::draw() {
  for (int targetIndex=0; targetIndex<objectList.size(); targetIndex++) {
    ObjectBehavior* targetObject = objectList[targetIndex];
    if ( targetObject == nullptr ) { continue; }
    targetObject->draw();
  }
}

void ObjectManager::destroyObjects() {
  for (int targetIndex=0; targetIndex<objectList.size(); targetIndex++) {
    ObjectBehavior* targetObject = objectList[targetIndex];
    if ( targetObject == nullptr ) { continue; }
    targetObject->destroy();
  }
  awakenObjectList.clear();
  objectList.clear();
  rigidObjectList.clear();
  movableRigidObjectList.clear();
}


NS_END
