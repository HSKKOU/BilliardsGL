//
//  Base3DController.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/22.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef Base3DController_hpp
#define Base3DController_hpp

#include "GlobalHeader.h"
#include "Base3D.h"

NS_ENGINE

class Base3DController : public Base3D {
  
public:
  Base3DController();
  Base3DController(Transform t);
  virtual ~Base3DController();
  
  void virtual awake();
  void virtual start();
  void virtual update();
  void virtual lateUpdate();
};

NS_END

#endif /* Base3DController_hpp */
