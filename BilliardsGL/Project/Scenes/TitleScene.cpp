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

TitleScene::TitleScene() { /* do nothing */ }
TitleScene::~TitleScene() { /* do nothing */ }

void TitleScene::enter() {
  titleManager = &(TitleManager::instance());
  titleManager->initialize();
  (ObjectManager::instance()).registerObject(titleManager);
  
  SceneBase::enter();
}

void TitleScene::exit() {
  SceneBase::exit();
}


NS_END
