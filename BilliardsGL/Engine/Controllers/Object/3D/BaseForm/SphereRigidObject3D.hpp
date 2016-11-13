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

NS_ENGINE

class SphereRigidObject3D : public BaseRigidObject3D {
  GLfloat radius;
  
public:
  SphereRigidObject3D(Transform t, GLfloat mass, GLfloat r);
  virtual ~SphereRigidObject3D();
  
  void virtual updatePhysics(GLfloat deltaTime);
};

NS_END

#endif /* SphereRigidObject3D_hpp */
