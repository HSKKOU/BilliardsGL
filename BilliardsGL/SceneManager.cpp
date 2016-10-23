//
//  SceneManager.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/20.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "SceneManager.hpp"

// for Debug
#include "GameScene.hpp"

NS_ENGINE

SceneManager::SceneManager()
{ /* do nothing */ }
SceneManager::~SceneManager() { /* do nothing */ }

void SceneManager::initialize() {
  // for Debug
  Game::GameScene* gameScene = new Game::GameScene();
  addScene(gameScene);
  currentScene = gameScene;
}

void SceneManager::addScene(SceneBase* scene) {
  scenes.emplace_back(scene);
}

SceneBase* SceneManager::getScene(int index) const {
  if (index < 0 || index >= scenes.size()) { return nullptr; }
  return scenes.at(index);
}

void SceneManager::removeScene(int index) {
  if (index < 0 || index >= scenes.size()) { return; }
  scenes.erase(scenes.begin()+index);
}

void SceneManager::switchSceneTo(int index) {
  if (index < 0 || index >= scenes.size()) { return; }
  SceneBase* nextScene = scenes.at(index);
  switchSceneTo(nextScene);
}

void SceneManager::switchSceneTo(SceneBase* scene) {
  if (!scene) { return; }
  if (!currentScene) { currentScene->exit(); }
  currentScene = scene;
  currentScene->enter();
}

void SceneManager::updateScene() const {
  currentScene->update();
}

NS_END
