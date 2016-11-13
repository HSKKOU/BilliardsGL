//
//  UIPanel.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/13.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "UIPanel.hpp"

NS_ENGINE_UI

UIPanel::UIPanel(Point2D p, Vector2D s, Color c)
: Engine::SquareObject2D(p, s)
, panelColor(c)
{ /* do nothing */ }

UIPanel::~UIPanel() { /* do nothing */ }

NS_END2
