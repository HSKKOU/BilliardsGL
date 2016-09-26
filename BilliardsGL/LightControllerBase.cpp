//
//  LightControllerBase.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/26.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "LightControllerBase.hpp"

LightControllerBase::LightControllerBase(Vector3D _position, Vector3D _diffuse = Vector3D::one(), Vector3D _ambient = Vector3D::one(), Vector3D _specular = Vector3D::one())
: Base3D(_position)
, diffuse(_diffuse)
, ambient(_ambient)
, specular(_specular)
{
  
}

LightControllerBase::~LightControllerBase() { /* do nothing */ }

Vector3D LightControllerBase::getDiffuse() { return diffuse; }
void LightControllerBase::setDiffuse(Vector3D _diffuse) { diffuse = _diffuse; }

Vector3D LightControllerBase::getAmbient() { return ambient; }
void LightControllerBase::setAmbient(Vector3D _ambient) { ambient = _ambient; }

Vector3D LightControllerBase::getSpecular() { return specular; }
void LightControllerBase::setSpecular(Vector3D _specular) { specular = _specular; }
