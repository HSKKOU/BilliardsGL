//
//  InputManager.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/13.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "InputManager.hpp"

NS_ENGINE

InputManager::InputManager() { /* do nothing */ }
InputManager::~InputManager() { uiManagerDelegate = nullptr; }

void InputManager::setUIManagerDelegate(UIManager* delegate) { uiManagerDelegate = delegate; }

void InputManager::pressedButton(EButton btn, Point2D point) {
  calcMousePointCentering(point);
//  std::cout << "pressed button  " << static_cast<int>(btn) << ": [" << point.x << ", " << point.y << "]" << std::endl;
  uiManagerDelegate->recieveEventPressed(point);
}

void InputManager::releasedButton(EButton btn, Point2D point) {
  calcMousePointCentering(point);
//  std::cout << "released button " << static_cast<int>(btn) << ": [" << point.x << ", " << point.y << "]" << std::endl;
  uiManagerDelegate->recieveEventReleased(point);
}

void InputManager::calcMousePointCentering(Point2D& point) {
  point.x = point.x - Const::WINDOW_WIDTH/2;
  point.y = Const::WINDOW_HEIGHT/2 - point.y;
}

NS_END
