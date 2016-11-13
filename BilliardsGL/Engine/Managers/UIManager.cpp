//
//  UIManager.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/13.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "UIManager.hpp"

NS_ENGINE

UIManager::UIManager() { /* do nothing */ }
UIManager::~UIManager() {
  for (UIButton* btn : buttonList) { delete btn; btn = nullptr; }
  buttonList.clear();
}

void UIManager::initialize() { /* do nothing */ }


void UIManager::registerButton(UIButton* button) { buttonList.emplace_back(button); }

void UIManager::recieveEventPressed(Point2D p) {
  for (int i=0; i<buttonList.size(); i++) {
    UIButton* button = buttonList[i];
    if (!button->isInRange(p)) {
      if (button->isPressed()) { button->release(); }
      continue;
    }
    if (!button->isPressed()) { button->press(); }
    button->pressRepeat();
  }
}

void UIManager::recieveEventReleased(Point2D p) {
  for (int i=0; i<buttonList.size(); i++) {
    UIButton* button = buttonList[i];
    if (!button->isInRange(p)) { continue; }
    if (button->isPressed()) { button->release(); }
  }
}

NS_END
