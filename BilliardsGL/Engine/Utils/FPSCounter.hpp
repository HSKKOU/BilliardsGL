//
//  FPSCounter.h
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/23.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef FPSCounter_h
#define FPSCounter_h

#include "Singleton.h"
#include <cmath>

NS_ENGINE_UTIL

class FPSCounter : public Singleton<FPSCounter> {
  friend class Singleton<FPSCounter>;
  
  // last looping time
  double lastTime = 0.0;
  // last passed 1sec
  double lastSec = 0.0;
  // frame count in 1 sec.
  double currentFPS = 0.0;
  
  // show flag
  bool isShowFPS = false;
  
public:
  void initialize(double, bool);
  double update(double);
  double getFPS() const;
  bool isStable() const;
  
private:
  FPSCounter();
};

NS_END2

#endif /* FPSCounter_h */
