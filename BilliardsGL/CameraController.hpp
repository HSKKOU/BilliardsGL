//
//  CameraController.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/26.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef CameraController_hpp
#define CameraController_hpp

#include "GlobalHeader.h"
#include "Base3D.h"

class CameraController : public Base3D {
  
public:
  CameraController(Vector3D);
  virtual ~CameraController();
  
};

#endif /* CameraController_hpp */
