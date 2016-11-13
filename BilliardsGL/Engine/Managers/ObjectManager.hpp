//
//  ObjectManager.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/07.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef ObjectManager_hpp
#define ObjectManager_hpp


#include <vector>
#include <list>

#include "Singleton.h"
#include "Objects.h"
#include "CollisionCalculator.hpp"

US_NS_ENGINE_MODEL

NS_ENGINE

class ObjectManager : public Singleton<ObjectManager> {
  friend class Singleton<ObjectManager>;
  
  std::vector<ObjectBehavior*> awakenObjectList;
  std::vector<ObjectBehavior*> objectList;
  std::vector<BaseRigidObject3D*> rigidObjectList;
  std::vector<BaseRigidObject3D*> movableRigidObjectList;
  
public:
  void initialize();
  ObjectBehavior* registerObject(ObjectBehavior* object);
  ObjectBehavior* getObject(const int objectId) const;
  void destroyObject(const int objectId) const;
  
  /* Life Cycles */
  void startAwakenObjects();
  
  void updateObjectsPhysics(GLfloat deltaTime);

  void updateObjects(GLfloat deltaTime);
  void lateUpdateObjects(GLfloat deltaTime);
  
  void draw();
  
  void destroyObjects();
  /* end Life Cycles */
  
private:
  ObjectManager();
};

NS_END

#endif /* ObjectManager_hpp */
