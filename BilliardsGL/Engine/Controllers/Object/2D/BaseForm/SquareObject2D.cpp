//
//  SquareObject2D.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/13.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "SquareObject2D.hpp"

NS_ENGINE

SquareObject2D::SquareObject2D(Point2D p, Vector2D s)
: Engine::BaseObject2D(p)
, size(s)
{ /* do nothing */ }

SquareObject2D::~SquareObject2D() { /* do nothing */ }


void SquareObject2D::createSquareModel(ETex tex, Color c) {
  Square* squareModel = ModelFactory::createSquareModel(size);
  squareModel->setPosition(position);
  squareModel->setTexture(tex);
  squareModel->setObjectColor(c);
  modelList.emplace_back(squareModel);
}


NS_END
