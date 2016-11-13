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
InputManager::~InputManager() { /* do nothing */ }

void InputManager::initialize() { /* do nothing */ }


void InputManager::pressedButton(EButton btn, Point2D point) {
//  std::cout << "pressed button  " << static_cast<int>(btn) << ": [" << point.x << ", " << point.y << "]" << std::endl;
}

void InputManager::releasedButton(EButton btn, Point2D point) {
//  std::cout << "released button " << static_cast<int>(btn) << ": [" << point.x << ", " << point.y << "]" << std::endl;
}

NS_END
