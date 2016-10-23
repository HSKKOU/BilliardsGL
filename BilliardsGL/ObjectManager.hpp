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

#include "Objects.h"

US_NS_ENGINE_MODEL

NS_ENGINE

class ObjectManager : public Singleton<ObjectManager> {
  friend class Singleton<ObjectManager>;
  
  std::list<ObjectBehavior*> objectList;
  
public:
  void initialize();
  ObjectBehavior* registerObject(ObjectBehavior* object);
  ObjectBehavior* getObject(const int objectId) const;
  void destroyObject(const int objectId) const;
  
  void awakeObjects();
  void startObjects();
  void updateObjects();
  void lateUpdateObjects();
  
private:
  ObjectManager();
};

NS_END

#endif /* ObjectManager_hpp */
