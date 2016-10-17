//
//  Cube.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/25.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "Cube.hpp"

Cube::Cube(const Vector3D _center, const Vector3D _size) : BaseObject3D(_center), size(_size) {
  GLfloat vPos[6*2*3][3+2+3] = {
    // front
    { -size.x, -size.y, -size.z,    0.0f, 0.0f },
    { +size.x, -size.y, -size.z,    1.0f, 0.0f },
    { +size.x, +size.y, -size.z,    1.0f, 1.0f },
    { +size.x, +size.y, -size.z,    1.0f, 1.0f },
    { -size.x, +size.y, -size.z,    0.0f, 1.0f },
    { -size.x, -size.y, -size.z,    0.0f, 0.0f },
    
    // back
    { +size.x, +size.y, +size.z,    1.0f, 1.0f },
    { +size.x, -size.y, +size.z,    1.0f, 0.0f },
    { -size.x, -size.y, +size.z,    0.0f, 0.0f },
    { -size.x, -size.y, +size.z,    0.0f, 0.0f },
    { -size.x, +size.y, +size.z,    0.0f, 1.0f },
    { +size.x, +size.y, +size.z,    1.0f, 1.0f },
    
    // right
    { +size.x, -size.y, -size.z,    0.0f, 0.0f },
    { +size.x, -size.y, +size.z,    0.0f, 1.0f },
    { +size.x, +size.y, +size.z,    1.0f, 1.0f },
    { +size.x, +size.y, +size.z,    1.0f, 1.0f },
    { +size.x, +size.y, -size.z,    1.0f, 0.0f },
    { +size.x, -size.y, -size.z,    0.0f, 0.0f },
    
    // left
    { -size.x, +size.y, +size.z,    1.0f, 1.0f },
    { -size.x, -size.y, +size.z,    0.0f, 1.0f },
    { -size.x, -size.y, -size.z,    0.0f, 0.0f },
    { -size.x, -size.y, -size.z,    0.0f, 0.0f },
    { -size.x, +size.y, -size.z,    1.0f, 0.0f },
    { -size.x, +size.y, +size.z,    1.0f, 1.0f },
    
    // up
    { -size.x, +size.y, -size.z,    0.0f, 0.0f },
    { +size.x, +size.y, -size.z,    1.0f, 0.0f },
    { +size.x, +size.y, +size.z,    1.0f, 1.0f },
    { +size.x, +size.y, +size.z,    1.0f, 1.0f },
    { -size.x, +size.y, +size.z,    0.0f, 1.0f },
    { -size.x, +size.y, -size.z,    0.0f, 0.0f },
    
    // down
    { +size.x, -size.y, +size.z,    1.0f, 1.0f },
    { +size.x, -size.y, -size.z,    1.0f, 0.0f },
    { -size.x, -size.y, -size.z,    0.0f, 0.0f },
    { -size.x, -size.y, -size.z,    0.0f, 0.0f },
    { -size.x, -size.y, +size.z,    0.0f, 1.0f },
    { +size.x, -size.y, +size.z,    1.0f, 1.0f },
  };
  
  const GLfloat normals[6][3] = {
    { 0.0f, 0.0f,-1.0f },
    { 0.0f, 0.0f, 1.0f },
    { 1.0f, 0.0f, 0.0f },
    {-1.0f, 0.0f, 0.0f },
    { 0.0f, 1.0f, 0.0f },
    { 0.0f,-1.0f, 0.0f },
  };
  for (int i=0; i<6; i++) {
    for (int j=0; j<2*3; j++) {
      for (int k=0; k<3; k++) {
        vPos[i*2*3+j][3+2+k] = normals[i][k];
      }
    }
  }
  
  setObjectColor(Color(1.0f, 1.0f, 1.0, 1.0f));

  loadShaderProgram();

  vertices.count = sizeof(vPos)/sizeof(vPos[0]);
  vertices.vao = createModel(vPos, vertices.count, 3, 2, 3);
}

Cube::~Cube() { /* do nothing */ }

void Cube::draw() {
  drawReady();
  
  mvp.model = Matrix4D(1.0f);
  mvp.model = Matrix4D::translate(mvp.model, Vector3D(sinf((GLfloat)glfwGetTime())*2.0f, 0.0f, 0.0f));
//  mvp.model = Matrix4D::rotate(mvp.model, Vector3D(1.0f, 1.0f, 1.0f).normalize(), (GLfloat)glfwGetTime());
//  mvp.model = Matrix4D::scale(mvp.model, Vector3D((GLfloat)glfwGetTime(), 1.0f, (GLfloat)glfwGetTime()));
  
//  setObjectColor(Color(0.1f*(GLfloat)glfwGetTime(), 0.0f, 0.0f, 1.0f));

  sendMVP2Shd();
  sendColor2Shd();
  sendLightInfo2Shd();

  GLuint texId = (TextureLoader::instance()).getTextureId(Tex::Stone);
  glBindTexture(GL_TEXTURE_2D, texId);
  glDrawElements(GL_TRIANGLES, 6*2*3, GL_UNSIGNED_INT, 0);
  
  drawRun();
}
