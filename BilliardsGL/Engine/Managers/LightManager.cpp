//
//  LightManager.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/26.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "LightManager.hpp"

NS_ENGINE

LightManager::LightManager() { glCullFace(GL_FRONT); }
LightManager::~LightManager() { SAFE_DELETE_VECTOR(lightCtrls, LightControllerBase); }

LightControllerBase* LightManager::getLight() const { return lightCtrls[0]; }

LightControllerBase* LightManager::getLight(const int index) const { return lightCtrls[index]; }

void LightManager::addLight(LightControllerBase *light) { lightCtrls.push_back(light); }

void LightManager::updateLights() {
  for (LightControllerBase *light : lightCtrls) {
    light->updateLight();
  }
}




/* - Shadow Mapper ------------------ */

ShadowMapper::ShadowMapper() : depthMap(0), depthMapFBO(0) {
  glGenFramebuffers(1, &depthMapFBO);
  
  glGenTextures(1, &depthMap);
  glBindTexture(GL_TEXTURE_2D, depthMap);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, 1024, 1024, 0, GL_DEPTH_COMPONENT, GL_FLOAT, nullptr);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  
  glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
  glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthMap, 0);
  
  glDrawBuffer(GL_NONE);
  glReadBuffer(GL_NONE);
  
  glBindTexture(GL_TEXTURE_2D, 0);
  glBindFramebuffer(GL_FRAMEBUFFER, 0);
}
ShadowMapper::~ShadowMapper() { /* do nothing */ }

GLuint ShadowMapper::getDepthMap() const { return depthMapFBO; }
GLuint ShadowMapper::getDepthMapFBO() const { return depthMap; }

NS_END
