//
//  TitleScene.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/11.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "TitleScene.hpp"

#include "Scenes.h"
#include "SceneManager.hpp"

NS_GAME

TitleScene::TitleScene() : updateCnt(0) { /* do nothing */ }
TitleScene::~TitleScene() { /* do nothing */ }

void TitleScene::enter() {
  SceneBase::enter();
}

void TitleScene::exit() {
  SceneBase::exit();
}

void TitleScene::update(GLfloat deltaTime) {
  SceneBase::update(deltaTime);
  updateCnt++;
  if (updateCnt >= 60) {
    (SceneManager::instance()).switchSceneTo(Scenes::Game);
  }
}

NS_END
