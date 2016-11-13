//
//  Square.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/23.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "Square.hpp"

NS_ENGINE_MODEL

Square::Square(Point2D _center, Vector2D _size)
: BaseModel2D(_center)
, size(_size)
{
  GLfloat vPos[6][2+2] = {
//  { pos.x  , pos.y  ,    uv.x, uv.y },
    
    {  size.x,  size.y,    1.0f, 1.0f },
    {  size.x, -size.y,    1.0f, 0.0f },
    { -size.x, -size.y,    0.0f, 0.0f },
    { -size.x, -size.y,    0.0f, 0.0f },
    { -size.x,  size.y,    0.0f, 1.0f },
    {  size.x,  size.y,    1.0f, 1.0f },
  };
  
  loadShaderProgram();
  
  vertices.count = sizeof(vPos)/sizeof(vPos[0]);
  vertices.vao = createModel(vPos, vertices.count, 2, 2);
}

Square::~Square() { /* do nothing */ }

NS_END2
