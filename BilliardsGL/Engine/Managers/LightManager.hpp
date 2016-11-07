//
//  LightManager.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/26.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef LightManager_hpp
#define LightManager_hpp

#include "GlobalHeader.h"
#include "Singleton.h"

#include <vector>

#include "LightControllerBase.hpp"

#include "DirectionalLightController.hpp"

US_NS_ENGINE_UTIL
US_NS_ENGINE_LIGHT

NS_ENGINE

class LightManager : public Singleton<LightManager> {
  friend class Singleton<LightManager>;
  
  std::vector<LightControllerBase*> lightCtrls;
  
public:
  virtual ~LightManager();
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
