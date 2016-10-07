//
//  ObjectManager.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/07.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef ObjectManager_hpp
#define ObjectManager_hpp

#include "GlobalHeader.h"
#include "Singleton.h"

#include <list>

#include "Models.h"
#include "ObjectFactory.hpp"

class ObjectManager : public Singleton<ObjectManager> {
  friend class Singleton<ObjectManager>;
  
  std::list<BaseObject3D*> objectList;
  
public:
  void initialize();
  BaseObject3D* instantiateObject(ObjectType type);
  BaseObject3D* getObject(int objectId);
  void destroyObject(int objectId);
  
  void updateObject();
  
private:
  ObjectManager();
};

#endif /* ObjectManager_hpp */
