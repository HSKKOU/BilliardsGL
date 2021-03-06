//
//  UIButton.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/13.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "UIButton.hpp"

#include "UIManager.hpp"

NS_ENGINE_UI

UIButton::UIButton(Point2D p, Vector2D s, ETex tex, UI_ALIGNMENT_MASK mask, Color c)
: Engine::UI::UIPanel(p, s, tex, mask, c)
, isPressedFlag(false)
{
  (UIManager::instance()).registerButton(this);
}

UIButton::~UIButton() { /* do nothing */ }


void UIButton::setHandler(IButtonHandler* hdl) { handler = hdl; }

void UIButton::awake() { UIPanel::awake(); }

bool UIButton::isPressed() const { return isPressedFlag; }
void UIButton::setIsPressedFlag(bool f) { isPressedFlag = f; }

bool UIButton::isInRange(Point2D p) const {
//  std::cout << "point [" << p.x << "," << p.y << "]" << std::endl;
//  std::cout << "UI range X [" << uiPosition.x - uiSize.x << "," << uiPosition.x + uiSize.x << "]" << std::endl;
//  std::cout << "UI range Y [" << uiPosition.y - uiSize.y << "," << uiPosition.y + uiSize.y << "]" << std::endl;

  // impl simple detection being in rectangle
  return
  (p.x > uiPosition.x - uiSize.x && p.x < uiPosition.x + uiSize.x)
  && (p.y > uiPosition.y - uiSize.y && p.y < uiPosition.y + uiSize.y);
}

void UIButton::press() {
  if (handler == nullptr) { return; }
  handler->onButtonDown();
  isPressedFlag = true;
}
void UIButton::pressRepeat() {
  if (handler == nullptr) { return; }
  handler->onButtonDownRepeat();
  isPressedFlag = true;
}
void UIButton::release() {
  if (handler == nullptr) { return; }
  handler->onButtonUp();
  isPressedFlag = false;
}

NS_END2
