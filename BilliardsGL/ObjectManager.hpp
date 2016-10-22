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

US_NS_ENGINE_MODEL

NS_ENGINE

class ObjectManager : public Singleton<ObjectManager> {
  friend class Singleton<ObjectManager>;
  
  std::list<BaseModel3D*> objectList;
  
public:
  void initialize();
  BaseModel3D* instantiateObject(ObjectType type);
  BaseModel3D* getObject(const int objectId) const;
  void destroyObject(const int objectId) const;
  
  void updateObject();
  
private:
  ObjectManager();
};

NS_END

#endif /* ObjectManager_hpp */
