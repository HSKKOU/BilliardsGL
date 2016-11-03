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

#include "BaseObject3D.hpp"

NS_ENGINE

class ColliderBase3D {
  
public:
  ColliderBase3D();
  virtual ~ColliderBase3D();
  
  virtual bool isCollideWith(BaseObject3D* object);
  
  virtual void onCollisionEnter(BaseObject3D* object) = 0;
  virtual void onCollisionStay(BaseObject3D* object) = 0;
  virtual void onCollisionExit(BaseObject3D* object) = 0;
};

NS_END

#endif /* ColliderBase3D_hpp */
