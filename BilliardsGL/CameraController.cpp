//
//  CameraController.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/26.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "CameraController.hpp"

CameraController::CameraController(Vector3D _pos, Vector3D _dir, Vector3D _up)
: Base3D(_pos)
, direction(_dir)
, upDir(_up)
, rightDir(_up.cross(_dir))
{
  
}

CameraController::~CameraController() {
  /* do nothing */
}

glm::mat4 CameraController::getViewMatrix() {
  return glm::lookAt(position.toVec3(), position.toVec3()+direction.toVec3(), upDir.toVec3());
}

Vector3D CameraController::getDirection() const { return direction; }
void CameraController::setDirection(const Vector3D _direction) { direction = _direction; }

void CameraController::lookAt(Vector3D target) { direction = target - position; }