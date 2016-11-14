//
//  ColliderBase3D.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/31.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef ColliderBase3D_hpp
#define ColliderBase3D_hpp

#include "GlobalHeader.h"
#include "Base3D.h"

NS_ENGINE

typedef uint64_t COL_MASK;

struct COL_TYPE {
  static const COL_MASK NONE   = 0b00;
  static const COL_MASK SPHERE = 0b01;
  static const COL_MASK CUBE   = 0b10;
};


class ColliderBase3D : Base3D {
  COL_MASK colliderType;
  
public:
  ColliderBase3D(Transform local, COL_MASK cType);
  virtual ~ColliderBase3D();
  
  Vector3D getPosition() const;
  COL_MASK getColliderType() const;
};

NS_END

#endif /* ColliderBase3D_hpp */
