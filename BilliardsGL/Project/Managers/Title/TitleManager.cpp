//
//  TitleManager.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/13.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "TitleManager.hpp"

#include "Constants.h"

NS_GAME

TitleManager::TitleManager() { /* do nothing */ }
TitleManager::~TitleManager() { destroy(); }

void TitleManager::initialize() {
  // set background color
  glClearColor(0.5f, 0.5f, 0.5f, 0.0f);
  
  panel = new UIPanel(Point2D(110.0f, 60.0f), Vector2D(100.0f, 50.0f), UI_ALIGNMENT::Top|UI_ALIGNMENT::Right, Color::one());
  (ObjectManager::instance()).registerObject(panel);
  
  button = new UIButton(Point2D(0.0f, -200.0f), Vector2D(200.0f, 80.0f), UI_ALIGNMENT::None, Color::one());
  button->setHandler(this);
  (ObjectManager::instance()).registerObject(button);
}

void TitleManager::awake() { /* do nothing */ }
void TitleManager::start() { /* do nothing */ }
void TitleManager::update(GLfloat deltaTime) { /* do nothing */ }

void TitleManager::destroy() {
  delete panel;
  panel = nullptr;
  delete button;
  button = nullptr;
}

void TitleManager::onButtonDown() {
  std::cout << "button down" << std::endl;
  (SceneManager::instance()).switchSceneTo(EScene::Game);
}
void TitleManager::onButtonDownRepeat() {
//  std::cout << "button down repeat" << std::endl;
}
void TitleManager::onButtonUp() {
  std::cout << "button up" << std::endl;
}

NS_END
