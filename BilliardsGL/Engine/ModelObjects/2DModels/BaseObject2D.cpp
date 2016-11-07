//
//  BaseObject2D.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/23.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "BaseObject2D.hpp"

NS_ENGINE_MODEL

BaseObject2D::BaseObject2D() {
  sizeLoc = glGetUniformLocation(shaderProgram, "size");
  scaleLoc = glGetUniformLocation(shaderProgram, "scale");
}

BaseObject2D::~BaseObject2D() {
  /* do nothing */
}

void BaseObject2D::draw() {
  /* do nothing */
}

NS_END2
