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

struct RigidBody {
  GLfloat mass;
  ColliderBase3D* collider;
  Vector3D velocity;
  RigidBody(GLfloat m = 0.0f, ColliderBase3D* col = nullptr, Vector3D vec = Vector3D::zero())
  : mass(m)
  , collider(col)
  , velocity(vec)
  { /* do nothing */ }
};

class BaseRigidObject3D : public BaseObject3D {
  
protected:
  const GLfloat GRAVITY = 9.8f;
  bool isStaticFlag;
  RigidBody rigidBody;

public:
  BaseRigidObject3D(Transform t, RigidBody rig, Surface surf);
  virtual ~BaseRigidObject3D();
  
  GLfloat getMass() const;
  Vector3D getVelocity() const;
  ColliderBase3D* getCollider3D() const;
  
  virtual bool isStatic() const;
  virtual bool isRigid() const;
  virtual bool isCollidable() const;
  
  void setIsStatic(bool flag);
  
  virtual void updatePhysics(GLfloat deltaTime);
  
  
  void addForce(float power, Vector3D dir);
  
  bool isCollideWith(BaseRigidObject3D* other);
  
  virtual void onCollisionEnter(BaseRigidObject3D* object);
  virtual void onCollisionStay(BaseRigidObject3D* object);
  virtual void onCollisionExit(BaseRigidObject3D* object);
};

NS_END

#endif /* BaseRigidObject3D_hpp */
