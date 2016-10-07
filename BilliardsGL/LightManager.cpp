//
//  LightManager.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/26.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "LightManager.hpp"

LightManager::LightManager() { /* do nothing */ }

void LightManager::initialize() {
  glCullFace(GL_FRONT);
}

LightControllerBase* LightManager::getLight() { return lightCtrls[0]; }

LightControllerBase* LightManager::getLight(int index) { return lightCtrls[index]; }

void LightManager::addLight(LightControllerBase *light) { lightCtrls.push_back(light); }

void LightManager::updateLights() {
  for (LightControllerBase *light : lightCtrls) {
    light->updateLight();
  }
}
