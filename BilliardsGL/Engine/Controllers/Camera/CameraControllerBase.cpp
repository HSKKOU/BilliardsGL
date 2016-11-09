//
//  CameraControllerBase.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/18.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "CameraControllerBase.hpp"

NS_ENGINE_CAMERA

CameraControllerBase::CameraControllerBase(Transform t)
: Base3D(t)
, projectionMatrix(Matrix4D::zero())
, viewMatrix(Matrix4D::zero())
{ /* do nothing */ }

CameraControllerBase::~CameraControllerBase() { /* do nothing */ }

Vector3D CameraControllerBase::getDirection() { return transform.forward(); }

Matrix4D CameraControllerBase::getProjectionMatrix() const { return projectionMatrix; }
Matrix4D CameraControllerBase::getViewMatrix() const { return viewMatrix; }

void CameraControllerBase::translateTo(Vector3D dest) {
  Base3D::translateTo(dest);
  calcViewMatrix();
}

void CameraControllerBase::rotation(Quaternion rot) {
  Base3D::rotation(rot);
  calcViewMatrix();
}

void CameraControllerBase::translate(Vector3D delta) {
  Base3D::translate(delta);
  calcViewMatrix();
}

void CameraControllerBase::rotate(Quaternion rot) {
  Base3D::rotate(rot);
  calcViewMatrix();
}

NS_END2
