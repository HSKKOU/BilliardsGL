//
//  DirectionalLightController.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/26.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef DirectionalLightController_hpp
#define DirectionalLightController_hpp

#include "GlobalHeader.h"

#include "LightControllerBase.hpp"

class DirectionalLightController : public LightControllerBase {
  Vector3D direction;
  
public:
  DirectionalLightController(Vector3D _position, Vector3D _direction, Vector3D _diffuse, Vector3D _ambient, Vector3D _specular);
  virtual ~DirectionalLightController();
  
  Vector3D getDirection();
  void setDirection(Vector3D);
};

#endif /* DirectionalLightController_hpp */
