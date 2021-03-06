//
//  CubeRigidObject3D.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/13.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef CubeRigidObject3D_hpp
#define CubeRigidObject3D_hpp

#include "Objects.h"

#include "Sphere.hpp"
#include "ModelFactory.hpp"

NS_ENGINE

class CubeRigidObject3D : public BaseRigidObject3D {
  Vector3D size;
  
public:
  CubeRigidObject3D(Transform t, Vector3D s, RigidBody rig, CubeCollider* col, Surface surf);
  CubeRigidObject3D(Transform t, Vector3D s, RigidBody rig, Surface surf);
  virtual ~CubeRigidObject3D();
  
  void setSize(Vector3D s);
  Vector3D getSize() const;
  
  virtual CubeCollider* getCollider3D() const;
  
  virtual void updatePhysics(GLfloat deltaTime);
  
  virtual bool isCollidedWithSphere(SphereRigidObject3D* sRig);
  
protected:
  virtual BaseModel3D* createModel();
};

NS_END

#endif /* CubeRigidObject3D_hpp */
