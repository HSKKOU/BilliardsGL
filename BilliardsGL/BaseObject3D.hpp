//
//  BaseObject3D.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/22.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef BaseObject3D_hpp
#define BaseObject3D_hpp

#include "GlobalHeader.h"
#include "Base3D.h"

NS_ENGINE

class BaseObject3D : public Base3D {
  
public:
  BaseObject3D();
  BaseObject3D(Transform t);
  virtual ~BaseObject3D();
  
  void virtual awake();
  void virtual start();
  void virtual update();
  void virtual lateUpdate();
};

NS_END

#endif /* BaseObject3D_hpp */
