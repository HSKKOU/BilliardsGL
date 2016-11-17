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

NS_ENGINE_LIGHT

class LightControllerBase : public Base3D {
  
protected:
  Vector3D diffuse;
  Vector3D ambient;
  Vector3D specular;
  Vector4D color;

  Vector3D direction;
  
  Matrix4D depthProjectionMatrix;
  Matrix4D depthViewMatrix;

  
public:
  LightControllerBase(
   Vector3D _position,
   Vector3D _diffuse = Vector3D::one(),
   Vector3D _ambient = Vector3D::one(),
   Vector3D _specular = Vector3D::one(),
   Vector4D _color = Vector4D::one(),
   Vector3D _direction = Vector3D::zero()
  );
  virtual ~LightControllerBase();
  
  Vector3D getDiffuse() const;
  void setDiffuse(Vector3D);
  Vector3D getAmbient() const;
  void setAmbient(Vector3D);
  Vector3D getSpecular() const;
  void setSpecular(Vector3D);
  Vector4D getColor() const;
  void setColor(Vector4D);
  
  virtual Vector3D getDirection() const;
  
  Matrix4D getDepthProjectionMatrix() const;
  Matrix4D getDepthViewMatrix() const;
  
  virtual void updateLight();
};

NS_END2

#endif /* LightControllerBase_hpp */
