//
//  SceneFactory.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/11.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "SceneFactory.hpp"

#include "TitleScene.hpp"
#include "GameScene.hpp"

NS_ENGINE_SCENE

SceneBase* SceneFactory::initializeScene(EScene scene) {
  switch (scene) {
    case EScene::Title : return new Game::TitleScene();
    case EScene::Game  : return new Game::GameScene();
    default: return nullptr;
  }
}

NS_END2
