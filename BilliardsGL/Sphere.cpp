//
//  Sphere.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/07.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "Sphere.hpp"

Sphere::Sphere(const Vector3D _center, const GLfloat _radius, const int _slices, const int _stacks)
: BaseObject3D(_center)
, radius(_radius)
{
  GLfloat vPos[2*3*_slices*_stacks][3+3];
  float angSlice = 2.0 * M_PI / _slices;
  float angStack = M_PI / _stacks;
  for (int i=0; i<_stacks; i++) {
    for (int j=0; j<_slices; j++) {
      int index = (i+_stacks*j)*2*3;
      setVPos(vPos[index+0], angStack*i, angSlice*j);
      setVPos(vPos[index+1], angStack*(i+1), angSlice*j);
      setVPos(vPos[index+2], angStack*i, angSlice*(j+1));

      setVPos(vPos[index+3], angStack*i, angSlice*(j+1));
      setVPos(vPos[index+4], angStack*(i+1), angSlice*j);
      setVPos(vPos[index+5], angStack*(i+1), angSlice*(j+1));
    }
  }

  setObjectColor(Color(1.0f, 0.0f, 0.0, 1.0f));
  
  loadShaderProgram();
  
  vertices.count = (GLsizei)(sizeof(vPos)/sizeof(vPos[0]));
  vertices.vao = createModel(vPos, vertices.count, 3, 3);
}

void Sphere::setVPos(GLfloat *vPos, float ast, float asl) {
  // position
  vPos[0] = radius * sinf(ast) * cosf(asl);
  vPos[1] = radius * cosf(ast);
  vPos[2] = radius * sinf(ast) * sinf(asl);
  
  // normal
  vPos[3+0] = vPos[0];
  vPos[3+1] = vPos[1];
  vPos[3+2] = vPos[2];
}

Sphere::~Sphere() { /* do nothing */ }

void Sphere::draw() {
  drawReady();
  
  mvp.model = Matrix4D(1.0f);
  mvp.model = Matrix4D::translate(mvp.model, Vector3D((GLfloat)glfwGetTime()*0.3f, 0.0f, 0.0f));
  mvp.model = Matrix4D::rotate(mvp.model, Vector3D(1.0f, 1.0f, 1.0f).normalize(), (GLfloat)glfwGetTime());
  
//  setObjectColor(Color(0.1f*(GLfloat)glfwGetTime(), 0.0f, 0.0f, 1.0f));
  
  sendMVP2Shd();
  sendColor2Shd();
  sendLightInfo2Shd();
  
  drawRun();
}
