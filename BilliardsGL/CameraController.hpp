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
  Vector3D direction;
  Vector3D upDir;
  
public:
  CameraController(Vector3D pos, Vector3D dir, Vector3D up = Vector3D::up());
  virtual ~CameraController();
  
};

#endif /* CameraController_hpp */
