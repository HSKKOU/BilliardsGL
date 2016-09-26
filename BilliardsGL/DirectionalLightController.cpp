//
//  DirectionalLightController.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/26.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "DirectionalLightController.hpp"

DirectionalLightController::DirectionalLightController(Vector3D _position, Vector3D _direction = Vector3D::down(), Vector3D _diffuse = Vector3D::one(), Vector3D _ambient = Vector3D::one(), Vector3D _specular = Vector3D::one())
: LightControllerBase(_position, _diffuse, _ambient, _specular)
, direction(_direction)
{
  
}

DirectionalLightController::~DirectionalLightController() { /* do nothing */ }

Vector3D DirectionalLightController::getDirection() { return direction; }
void DirectionalLightController::setDirection(Vector3D _direction) { direction = _direction; }
