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

#include "CameraController.hpp"

#include <vector>

class CameraManager : public Singleton<CameraManager> {
  friend class Singleton<CameraManager>;
  
  std::vector<CameraController*> cameraCtrls;
  
public:
  void initialize();
  CameraController* getCamera() const;
  CameraController* getCamera(const int) const;
  void addCamera(CameraController*);
  
private:
  CameraManager();
};

#endif /* CameraManager_hpp */
