//
//  SceneManager.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/20.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "SceneManager.hpp"

#include "SceneFactory.hpp"

NS_ENGINE

SceneManager::SceneManager()
: currentScene(nullptr)
{
  for (int i=0; i<static_cast<int>(EScene::Num); i++) {
    SceneBase* scene = SceneFactory::initializeScene(static_cast<EScene>(i));
    if (!scene) {
      std::cout << "There is no Scene index of " << i << std::endl;
      exit(EXIT_FAILURE);
      return;
    }
    addScene(scene);
  }
}
SceneManager::~SceneManager() {
  SAFE_DELETE_VECTOR(scenes, SceneBase);
  currentScene = nullptr;
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

void SceneManager::switchSceneTo(EScene scene) { switchSceneTo(static_cast<int>(scene)); }

void SceneManager::switchSceneTo(SceneBase* scene) {
  if (!scene) { return; }
  if (currentScene) { currentScene->exit(); }
  currentScene = scene;
  currentScene->enter();
}

void SceneManager::startFirstScene() {
  switchSceneTo(0);
}

void SceneManager::updateScene(GLfloat deltaTime) const {
  currentScene->update(deltaTime);
}

NS_END
