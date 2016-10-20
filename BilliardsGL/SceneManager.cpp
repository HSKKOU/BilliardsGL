//
//  SceneManager.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/20.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "SceneManager.hpp"

#include "TestScene001.hpp"

SceneManager::SceneManager()
{ /* do nothing */ }
SceneManager::~SceneManager() { /* do nothing */ }

void SceneManager::initialize() {
  // for Debug
  TestScene001* testScene = new TestScene001();
  addScene(testScene);
  currentScene = testScene;
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
  currentScene = scenes.at(index);
}

void SceneManager::switchSceneTo(SceneBase* scene) {
  if (scene) { currentScene = scene; }
}


void SceneManager::startScene() const {
  currentScene->start();
}

void SceneManager::updateScene() const {
  currentScene->update();
}
