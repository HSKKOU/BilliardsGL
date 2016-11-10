//
//  BaseRigidObject3D.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/31.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef BaseRigidObject3D_hpp
#define BaseRigidObject3D_hpp

#include "BaseObject3D.hpp"

#include "Collisions.h"

NS_ENGINE

class BaseRigidObject3D : public BaseObject3D {
protected:
  GLfloat mass;
  Vector3D velocity;
  
  ColliderBase3D* collider;
  
public:
  BaseRigidObject3D(Transform t, GLfloat mass, ColliderBase3D* col);
  virtual ~BaseRigidObject3D();
  
  GLfloat getMass() const;
  Vector3D getVelocity() const;
  ColliderBase3D* getCollider3D() const;
  
  void setVelocity(Vector3D v);
  
  virtual bool isRigid() const;
  virtual bool isCollidable() const;
  
  virtual void updatePhysics(GLfloat deltaTime);
  
  
  void addForce(float power, Vector3D dir);
  
  bool isCollideWith(BaseRigidObject3D* other) const;
  
  virtual void onCollisionEnter(BaseRigidObject3D* object);
  virtual void onCollisionStay(BaseRigidObject3D* object);
  virtual void onCollisionExit(BaseRigidObject3D* object);
};

NS_END

#endif /* BaseRigidObject3D_hpp */
