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

NS_ENGINE_LIGHT

class DirectionalLightController : public LightControllerBase {
  
public:
  DirectionalLightController(
   Vector3D _position,
   Vector3D _direction = Vector3D::down(),
   Vector3D _diffuse = Vector3D::one(),
   Vector3D _ambient = Vector3D::one(),
   Vector3D _specular = Vector3D::one(),
   Vector4D _color = Vector4D::one()
  );
  virtual ~DirectionalLightController();
  
  void setDirection(Vector3D);
  
  void updateLight();
};

NS_END2

#endif /* DirectionalLightController_hpp */
