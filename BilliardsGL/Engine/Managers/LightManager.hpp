//
//  LightManager.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/26.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef LightManager_hpp
#define LightManager_hpp

#include "Singleton.h"

#include <vector>

#include "LightControllerBase.hpp"

#include "DirectionalLightController.hpp"
#include "SpotLightController.hpp"

US_NS_ENGINE_UTIL
US_NS_ENGINE_LIGHT

NS_ENGINE

class ShadowMapper : public Singleton<ShadowMapper> {
  friend class Singleton<ShadowMapper>;
  
  GLuint depthMap;
  GLuint depthMapFBO;
  
public:
  ~ShadowMapper();
  void initialize();
  
  GLuint getDepthMap() const;
  GLuint getDepthMapFBO() const;
  
private:
  ShadowMapper();
};

class LightManager : public Singleton<LightManager> {
  friend class Singleton<LightManager>;
  
  std::vector<LightControllerBase*> lightCtrls;
  
public:
  ~LightManager();
  void initialize();
  LightControllerBase* getLight() const;
  LightControllerBase* getLight(const int) const;
  void addLight(LightControllerBase*);
  
  void updateLights();
  
private:
  LightManager();
};

NS_END

#endif /* LightManager_hpp */
