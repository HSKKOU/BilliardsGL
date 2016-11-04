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

#include "ColliderBase3D.hpp"

NS_ENGINE

class BaseRigidObject3D : public BaseObject3D {
protected:
  ColliderBase3D* collider;
  
public:
  BaseRigidObject3D(Transform t, ColliderBase3D* col);
  virtual ~BaseRigidObject3D();
  
  ColliderBase3D* getCollider3D() const;
  
  virtual void updatePhysics();
  
  virtual void onCollisionEnter(BaseRigidObject3D* object);
  virtual void onCollisionStay(BaseRigidObject3D* object);
  virtual void onCollisionExit(BaseRigidObject3D* object);
};

NS_END

#endif /* BaseRigidObject3D_hpp */
