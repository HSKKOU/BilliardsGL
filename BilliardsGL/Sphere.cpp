//
//  Sphere.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/07.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "Sphere.hpp"

NS_ENGINE_MODEL

Sphere::Sphere(const Vector3D _center, const GLfloat _radius, const int _slices, const int _stacks)
: BaseModel3D(_center)
, radius(_radius)
{
  GLfloat vPos[2*3*_slices*_stacks][3+2+3];
  float angSlice = 2.0 * M_PI / _slices;
  float angStack = M_PI / _stacks;
  for (int i=0; i<_stacks; i++) {
    for (int j=0; j<_slices; j++) {
      int index = (i+_stacks*j)*2*3;
      setVPos(vPos[index+0], i  , j  , _stacks, _slices, angStack, angSlice);
      setVPos(vPos[index+1], i  , j+1, _stacks, _slices, angStack, angSlice);
      setVPos(vPos[index+2], i+1, j  , _stacks, _slices, angStack, angSlice);

      setVPos(vPos[index+3], i  , j+1, _stacks, _slices, angStack, angSlice);
      setVPos(vPos[index+4], i+1, j+1, _stacks, _slices, angStack, angSlice);
      setVPos(vPos[index+5], i+1, j  , _stacks, _slices, angStack, angSlice);
    }
  }
  
  loadShaderProgram();
  
  vertices.count = (GLsizei)(sizeof(vPos)/sizeof(vPos[0]));
  vertices.vao = createModel(vPos, vertices.count, 3, 2, 3);
}

void Sphere::setVPos(GLfloat *vPos, int ist, int jsl, int stk, int slc, float ast, float asl) {
  float stackAng = ast * ist;
  float sliceAng = asl * jsl;
  
  // position
  vPos[    0] = radius * sinf(stackAng) * -sinf(sliceAng);
  vPos[    1] = radius * cosf(stackAng);
  vPos[    2] = radius * sinf(stackAng) * -cosf(sliceAng);

  // uv
  vPos[3+  0] = (float)jsl/slc;
  vPos[3+  1] = (float)ist/stk;
  
  // normal
  vPos[3+2+0] = vPos[0];
  vPos[3+2+1] = vPos[1];
  vPos[3+2+2] = vPos[2];
}

Sphere::~Sphere() { /* do nothing */ }

void Sphere::draw() {
  drawReady();
  sendParams2Shd();
  drawRun();
}

NS_END2
