//
//  Transform.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/22.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef Transform_hpp
#define Transform_hpp

#include "Matrix.h"

NS_ENGINE

struct Transform {
  Vector3D position;
  Quaternion rotation;
  Vector3D scale;
  
public:
  Transform(Vector3D pos, Quaternion rot = Quaternion::one(), Vector3D scl = Vector3D::one());
  virtual ~Transform();
  
  Vector3D up() const;
  Vector3D down() const;
  Vector3D left() const;
  Vector3D right() const;
  Vector3D forward() const;
  Vector3D back() const;
};

NS_END

#endif /* Transform_hpp */
