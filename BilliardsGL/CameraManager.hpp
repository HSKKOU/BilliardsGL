//
//  CameraManager.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/26.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef CameraManager_hpp
#define CameraManager_hpp

#include "GlobalHeader.h"
#include "Singleton.h"

#include "CameraControllerBase.hpp"

#include <vector>

US_NS_ENGINE_UTIL
US_NS_ENGINE_CAMERA

NS_ENGINE

class CameraManager : public Singleton<CameraManager> {
  friend class Singleton<CameraManager>;
  
  std::vector<CameraControllerBase*> cameraCtrls;
  
public:
  void initialize();
  CameraControllerBase* getCamera() const;
  CameraControllerBase* getCamera(const int) const;
  void addCamera(CameraControllerBase*);
  
private:
  CameraManager();
};

NS_END

#endif /* CameraManager_hpp */
