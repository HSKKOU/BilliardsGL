//
//  TitleManager.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/13.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "TitleManager.hpp"

NS_GAME

TitleManager::TitleManager() { /* do nothing */ }
TitleManager::~TitleManager() { /* do nothing */ }

void TitleManager::initialize() {
  // set background color
  glClearColor(0.5f, 0.5f, 0.5f, 0.0f);
}

void TitleManager::awake() { /* do nothing */ }
void TitleManager::start() { /* do nothing */ }
void TitleManager::update(GLfloat deltaTime) { /* do nothing */ }

NS_END