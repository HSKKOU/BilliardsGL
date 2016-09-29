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
  return glm::lookAt(position.vec, (position+direction).vec, upDir.vec);
}

Vector3D CameraController::getDirection() const { return direction; }
void CameraController::setDirection(const Vector3D _direction) { direction = _direction; }

void CameraController::lookAt(Vector3D target) { direction = target - position; }

Matrix4D CameraController::getProjection() { return projection; }
void CameraController::setPerspective(GLfloat _angle, GLfloat _aspect, GLfloat _near, GLfloat _far) {
  projection = Matrix4D::zero();
  angle = _angle;
  near = _near;
  far = _far;
  GLfloat dx = near * sinf(angle);
  GLfloat dy = near * sinf(angle) * _aspect;
  GLfloat dz = far - near;
  
  projection[0][0] = near / dx;
  projection[1][1] = near / dy;
  projection[2][2] = -(far + near) / dz;
  projection[2][3] = -2 * far * near / dz;
  projection[3][2] = -1;
}
void CameraController::setPerspective(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far) {
  projection = Matrix4D::zero();
  GLfloat dx = right - left;
  GLfloat dy = top - bottom;
  GLfloat dz = far - near;
  
  projection[0][0] = 2 * near / dx;
  projection[0][2] = (right + left) / dx;
  projection[1][1] = 2 * near / dy;
  projection[1][2] = (top + bottom) / dy;
  projection[2][2] = -(far + near) / dz;
  projection[2][3] = -2 * far * near / dz;
  projection[3][2] = -1;
}
