//
//  SceneManager.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/20.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "SceneManager.hpp"

SceneManager::SceneManager()
: currentScene(nullptr)
{ /* do nothing */ }
SceneManager::~SceneManager() { /* do nothing */ }

void SceneManager::initialize() { /* do nothing */ }

void SceneManager::addScene(const SceneBase* scene) {
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
  currentScene = scenes.at(index);
}

void SceneManager::switchSceneTo(SceneBase* scene) {
  if (scene) { currentScene = scene; }
}
