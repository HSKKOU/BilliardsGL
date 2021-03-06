//
//  UIPanel.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/13.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "UIPanel.hpp"

NS_ENGINE_UI

UIPanel::UIPanel(Point2D p, Vector2D s, ETex tex, UI_ALIGNMENT_MASK mask, Color c)
: Engine::UI::UIBase(p, s, tex, mask)
, panelColor(c)
{ /* do nothing */ }

UIPanel::~UIPanel() { /* do nothing */ }


void UIPanel::awake() {
  if (texture != ETex::None) {
    createSquareModel(texture, panelColor);
  }
}

NS_END2
