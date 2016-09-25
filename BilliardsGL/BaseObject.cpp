//
//  BaseObject.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/23.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "BaseObject.hpp"

BaseObject::BaseObject() {
  sizeLoc = glGetUniformLocation(shaderProgram, "size");
  scaleLoc = glGetUniformLocation(shaderProgram, "scale");
}

BaseObject::~BaseObject() {
  /* do nothing */
}

void BaseObject::draw() {
  /* do nothing */
}