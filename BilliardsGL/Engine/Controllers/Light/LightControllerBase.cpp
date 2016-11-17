//
//  LightControllerBase.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/26.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "LightControllerBase.hpp"

NS_ENGINE_LIGHT

LightControllerBase::LightControllerBase(
 Vector3D _position,
 Vector3D _diffuse,
 Vector3D _ambient,
 Vector3D _specular,
 Vector4D _color,
 Vector3D _direction
)
: Base3D(_position)
, diffuse(_diffuse)
, ambient(_ambient)
, specular(_specular)
, color(_color)
, direction(_direction.normalize())
{
//  glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse.v);
//  glLightfv(GL_LIGHT0, GL_AMBIENT, ambient.v);
//  glLightfv(GL_LIGHT0, GL_SPECULAR, specular.v);
}

LightControllerBase::~LightControllerBase() { /* do nothing */ }

Vector3D LightControllerBase::getDiffuse() const { return diffuse; }
void LightControllerBase::setDiffuse(Vector3D _diffuse) { diffuse = _diffuse; }

Vector3D LightControllerBase::getAmbient() const { return ambient; }
void LightControllerBase::setAmbient(Vector3D _ambient) { ambient = _ambient; }

Vector3D LightControllerBase::getSpecular() const { return specular; }
void LightControllerBase::setSpecular(Vector3D _specular) { specular = _specular; }

Vector4D LightControllerBase::getColor() const { return color; }
void LightControllerBase::setColor(Vector4D _color) { color = _color; }

Vector3D LightControllerBase::getDirection() const { return direction; }

Matrix4D LightControllerBase::getDepthProjectionMatrix() const { return depthViewMatrix; }
Matrix4D LightControllerBase::getDepthViewMatrix() const { return depthViewMatrix; }

void LightControllerBase::updateLight() {
  static GLfloat lightPos[4] = { 0.0f, 10.0f, 0.0f, 1.0f };
  glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
}

NS_END2
