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

void ObjectManager::initialize() {
  objectList = {};
}


// Object Control
BaseModel3D* ObjectManager::instantiateObject(ObjectType type) {
  BaseModel3D* object = ObjectFactory::instantiateObject(type);
  objectList.push_back(object);
  return object;
}

BaseModel3D* ObjectManager::getObject(const int objectId) const {
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

void ObjectManager::updateObject() {
  for (std::list<BaseModel3D*>::iterator itr = objectList.begin(); itr != objectList.end(); itr++) {
    if ( *itr == nullptr ) { continue; }
    (*itr)->draw();
  }
}

NS_END
