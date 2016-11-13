//
//  ObjectBehavior.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/23.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef ObjectBehavior_hpp
#define ObjectBehavior_hpp

#include "GlobalHeader.h"

NS_ENGINE

class ObjectBehavior {
  
public:
  ObjectBehavior();
  virtual ~ObjectBehavior();
  
  virtual bool isRigid() const;
  virtual bool isCollidable() const;
  virtual bool isStatic() const;
  
  virtual void awake();
  virtual void start();
  
  virtual void updatePhysics(GLfloat deltaTime);
  
  virtual void update(GLfloat deltaTime);
  virtual void lateUpdate(GLfloat deltaTime);
  
  virtual void draw();
  
  virtual void destroy();
};

NS_END

#endif /* ObjectBehavior_hpp */
