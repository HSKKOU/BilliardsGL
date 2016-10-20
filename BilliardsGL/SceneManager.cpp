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

void SceneManager::initialize() {}

void SceneManager::addScene(const SceneBase* scene) {
  
}

SceneBase* SceneManager::getScene(int index) const {
  return nullptr;
}

void SceneManager::removeScene(int index) {
  
}

void SceneManager::switchSceneTo(int index) {
  
}

void SceneManager::switchSceneTo(SceneBase* scene) {
  
}
