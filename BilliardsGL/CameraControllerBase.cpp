//
//  CameraControllerBase.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/18.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "CameraControllerBase.hpp"

CameraControllerBase::CameraControllerBase(Vector3D _pos, Vector3D _center, Vector3D _up)
: Base3D(_pos)
, center(_center)
, upDir(_up)
, projectionMatrix(Matrix4D::zero())
, viewMatrix(Matrix4D::zero())
{ /* do nothing */ }

CameraControllerBase::~CameraControllerBase() {
  /* do nothing */
}

Vector3D CameraControllerBase::getDirection() { return center - transform.position; }

Matrix4D CameraControllerBase::getProjectionMatrix() const { return projectionMatrix; }
Matrix4D CameraControllerBase::getViewMatrix() const { return viewMatrix; }

void CameraControllerBase::translate(Vector3D dest) {
  Base3D::translate(dest);
}

void CameraControllerBase::rotate(Quaternion rot) {
  Base3D::rotate(rot);
}
