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

void ObjectManager::initialize() { /* do nothing */ }


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
    objectList.push_back(ob);
  }
  awakenObjectList.clear();
}

void ObjectManager::updateObjectsPhysics(GLfloat deltaTime) {
  for (std::list<ObjectBehavior*>::iterator itr = objectList.begin(); itr != objectList.end(); itr++) {
    if ( *itr == nullptr ) { continue; }
    (*itr)->updatePhysics(deltaTime);
  }
}

void ObjectManager::updateObjects(GLfloat deltaTime) {
  for (std::list<ObjectBehavior*>::iterator itr = objectList.begin(); itr != objectList.end(); itr++) {
    if ( *itr == nullptr ) { continue; }
    (*itr)->update(deltaTime);
  }
}

void ObjectManager::lateUpdateObjects(GLfloat deltaTime) {
  for (std::list<ObjectBehavior*>::iterator itr = objectList.begin(); itr != objectList.end(); itr++) {
    if ( *itr == nullptr ) { continue; }
    (*itr)->lateUpdate(deltaTime);
  }
}

void ObjectManager::draw() {
  for (std::list<ObjectBehavior*>::iterator itr = objectList.begin(); itr != objectList.end(); itr++) {
    if ( *itr == nullptr ) { continue; }
    (*itr)->draw();
  }
}

void ObjectManager::destroyObjects() {
  for (std::list<ObjectBehavior*>::iterator itr = objectList.begin(); itr != objectList.end(); itr++) {
    if ( *itr == nullptr ) { continue; }
    (*itr)->destroy();
  }
}


NS_END
