//
//  LightControllerBase.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/26.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef LightControllerBase_hpp
#define LightControllerBase_hpp

#include "GlobalHeader.h"
#include "Base3D.h"

class LightControllerBase : public Base3D {
  
protected:
  Vector3D diffuse;
  Vector3D ambient;
  Vector3D specular;
  Vector4D color;
  
public:
  LightControllerBase(Vector3D _position, Vector3D _diffuse, Vector3D _ambient, Vector3D _specular, Vector4D _color);
  virtual ~LightControllerBase();
  
  Vector3D getDiffuse();
  void setDiffuse(Vector3D);
  Vector3D getAmbient();
  void setAmbient(Vector3D);
  Vector3D getSpecular();
  void setSpecular(Vector3D);
  Vector4D getColor();
  void setColor(Vector4D);
  
  virtual void updateLight();
};

#endif /* LightControllerBase_hpp */
