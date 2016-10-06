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
  // set main light
  LightControllerBase *light0 = new DirectionalLightController(Vector3D::up()*10.0f, Vector3D::one(), Vector3D::one(), Vector3D::one()*0.25f, Vector3D::one(), Vector4D::one());
  
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  
  glShadeModel(GL_SMOOTH);
  
  glCullFace(GL_FRONT);

  addLight(light0);
}

LightControllerBase* LightManager::getLight() { return lightCtrls[0]; }

LightControllerBase* LightManager::getLight(int index) { return lightCtrls[index]; }

void LightManager::addLight(LightControllerBase *light) { lightCtrls.push_back(light); }

void LightManager::updateLights() {
  for (LightControllerBase *light : lightCtrls) {
    light->updateLight();
  }
}
