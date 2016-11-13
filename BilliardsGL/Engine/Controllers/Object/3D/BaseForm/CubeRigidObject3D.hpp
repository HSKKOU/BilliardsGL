//
//  CubeRigidObject3D.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/13.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef CubeRigidObject3D_hpp
#define CubeRigidObject3D_hpp

#include "BaseRigidObject3D.hpp"

NS_ENGINE

class CubeRigidObject3D : public BaseRigidObject3D {
  Vector3D size;
  
public:
  CubeRigidObject3D(Transform t, GLfloat mass, Vector3D s);
  virtual ~CubeRigidObject3D();
  
  virtual void updatePhysics(GLfloat deltaTime);
};

NS_END

#endif /* CubeRigidObject3D_hpp */
