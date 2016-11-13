//
//  UIPanel.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/13.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "UIPanel.hpp"

NS_ENGINE_UI

UIPanel::UIPanel(Point2D p, Vector2D s, UI_ALIGNMENT_MASK mask, Color c)
: Engine::UI::UIBase(p, s, mask)
, panelColor(c)
{ /* do nothing */ }

UIPanel::~UIPanel() { /* do nothing */ }


void UIPanel::awake() {
  UIBase::awake();
}

NS_END2
