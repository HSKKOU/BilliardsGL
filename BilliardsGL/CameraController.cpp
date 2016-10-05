//
//  CameraController.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/26.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "CameraController.hpp"

CameraController::CameraController(Vector3D _pos, Vector3D _center, Vector3D _up)
: Base3D(_pos)
, center(_center)
, upDir(_up)
, projection(Matrix4D::zero())
{
  
}

CameraController::~CameraController() {
  /* do nothing */
}

Matrix4D CameraController::getViewMatrix() {
  Vector3D f = (center - position).normalize();
  Vector3D s = f.cross(upDir).normalize();
  Vector3D u = s.cross(f);
  
  Matrix4D view = Matrix4D::one();
  view[0][0] = s.x;
  view[1][0] = s.y;
  view[2][0] = s.z;
  view[0][1] = u.x;
  view[1][1] = u.y;
  view[2][1] = u.z;
  view[0][2] =-f.x;
  view[1][2] =-f.y;
  view[2][2] =-f.z;
  view[3][0] =-s.dot(position);
  view[3][1] =-u.dot(position);
  view[3][2] = f.dot(position);
  
  return view;
}

Vector3D CameraController::getDirection() { return center - position; }

void CameraController::lookAt(Vector3D targetPos) { center = targetPos; }

Matrix4D CameraController::getProjection() const { return projection; }
void CameraController::setPerspective(const GLfloat _fovy, const GLfloat _aspect, const GLfloat _zNear, const GLfloat _zFar) {
  const GLfloat tanHalfFovy = tanf(_fovy / 2.0f);
  const GLfloat dz = _zNear - _zFar;
  const GLfloat f = _zFar;
  const GLfloat n = _zNear;
  const GLfloat fn = _zFar * _zNear;

  Matrix4D p = Matrix4D::zero();
  p[0][0] = 1.0f / (_aspect * tanHalfFovy);
  p[1][1] = 1.0f / tanHalfFovy;
  p[2][3] = -1.0f;
  p[2][2] = (f + n) / dz;
  p[3][2] = 2.0f * fn / dz;
  
  for (int i=0; i<4; i++) {
    for (int j=0; j<4; j++) {
      projection[i][j] = p[i][j];
    }
  }
}
