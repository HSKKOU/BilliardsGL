//
//  SpotLightController.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/18.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "SpotLightController.hpp"

NS_ENGINE_LIGHT

SpotLightController::SpotLightController(
  Vector3D _position,
  Vector3D _diffuse,
  Vector3D _ambient,
  Vector3D _specular,
  Vector4D _color
)
: LightControllerBase(_position, _diffuse, _ambient, _specular, _color, Vector3D::zero())
{ /* do nothing */ }

SpotLightController::~SpotLightController() { /* do nothing */ }

void SpotLightController::calcProjectionMatrix(const GLfloat _fovy, const GLfloat _aspect, const GLfloat _zNear, const GLfloat _zFar) {
  const float fovyRad = _fovy / 180.0f * M_PI;
  const GLfloat tanHalfFovy = tanf(fovyRad / 2.0f);
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
      depthProjectionMatrix[i][j] = p[i][j];
    }
  }
}

void SpotLightController::updateLight() {
  LightControllerBase::updateLight();
}

NS_END2
