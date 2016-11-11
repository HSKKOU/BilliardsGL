//
//  BaseModel2D.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/23.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "BaseModel2D.hpp"

NS_ENGINE_MODEL

BaseModel2D::BaseModel2D() {
  sizeLoc = glGetUniformLocation(shaderProgram, "size");
  scaleLoc = glGetUniformLocation(shaderProgram, "scale");
}

BaseModel2D::~BaseModel2D() {
  /* do nothing */
}

void BaseModel2D::draw() {
  /* do nothing */
}

NS_END2
