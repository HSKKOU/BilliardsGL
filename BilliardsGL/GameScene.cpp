//
//  GameScene.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/20.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "GameScene.hpp"

NS_GAME

GameScene::GameScene()
: gameManager(GameManager::instance())
{
  (ObjectManager::instance()).registerObject(&gameManager);
}
GameScene::~GameScene() { /* do nothing */ }

void GameScene::start() {
}

void GameScene::update() {
}

NS_END
