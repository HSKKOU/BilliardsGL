//
//  SphereRigidObject3D.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/12.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef SphereRigidObject3D_hpp
#define SphereRigidObject3D_hpp

#include "BaseRigidObject3D.hpp"

#include "Sphere.hpp"
#include "ModelFactory.hpp"

NS_ENGINE

class SphereRigidObject3D : public BaseRigidObject3D {
  GLfloat radius;
  
public:
  SphereRigidObject3D(Transform t, GLfloat r, RigidBody rig, Surface surf);
  virtual ~SphereRigidObject3D();
  
  void setRadius(GLfloat r);
  GLfloat getRadius() const;
  
  virtual void updatePhysics(GLfloat deltaTime);
  
protected:
  virtual BaseModel3D* createModel();
};

NS_END

#endif /* SphereRigidObject3D_hpp */
