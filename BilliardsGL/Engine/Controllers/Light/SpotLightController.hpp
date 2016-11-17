//
//  SpotLightController.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/18.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef SpotLightController_hpp
#define SpotLightController_hpp

#include "LightControllerBase.hpp"

NS_ENGINE_LIGHT

class SpotLightController : public LightControllerBase {
  
public:
  SpotLightController(
   Vector3D _position,
   Vector3D _diffuse = Vector3D::one(),
   Vector3D _ambient = Vector3D::one(),
   Vector3D _specular = Vector3D::one(),
   Vector4D _color = Vector4D::one()
  );
  virtual ~SpotLightController();
  
  virtual void calcProjectionMatrix(const GLfloat _fovy, const GLfloat _aspect, const GLfloat _zNear, const GLfloat _zFar);
  
  void updateLight();
};

NS_END2

#endif /* SpotLightController_hpp */
