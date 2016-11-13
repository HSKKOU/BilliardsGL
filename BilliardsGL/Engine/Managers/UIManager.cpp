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
UIManager::~UIManager() { destroyUIs(); }

void UIManager::initialize() { /* do nothing */ }


void UIManager::registerButton(UIButton* button) { buttonList.emplace_back(button); }

void UIManager::recieveEventPressed(Point2D p) {
  for (int i=0; i<buttonList.size(); i++) {
    UIButton* button = buttonList[i];
    if (!button->isInRange(p)) {
      
      // TODO : select correct method if out of Button Rectangle Range with Pressing.
//      if (button->isPressed()) { button->release(); }
      if (button->isPressed()) { button->setIsPressedFlag(false); }

      continue;
    }
    if (!button->isPressed()) { button->press(); }
    
    // remove Repeat Button Event
//    if (button != nullptr) { button->pressRepeat(); }
  }
}

void UIManager::recieveEventReleased(Point2D p) {
  for (int i=0; i<buttonList.size(); i++) {
    UIButton* button = buttonList[i];
    if (!button->isInRange(p)) { continue; }
    if (button->isPressed()) { button->release(); }
  }
}

void UIManager::destroyUIs() {
  for (UIButton* btn : buttonList) { delete btn; btn = nullptr; }
  buttonList.clear();
}

NS_END
