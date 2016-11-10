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

class ColliderBase3D : Base3D {
  Transform* parentTransform;
  
public:
  ColliderBase3D(Transform local);
  virtual ~ColliderBase3D();
  
  void setParentTransform(Transform* t);
  Vector3D getPosition() const;
};

NS_END

#endif /* ColliderBase3D_hpp */
