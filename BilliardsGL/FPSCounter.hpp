//
//  FPSCounter.h
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/23.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef FPSCounter_h
#define FPSCounter_h

#include <iostream>
#include "Singleton.h"

NS_ENGINE_UTIL

class FPSCounter : public Singleton<FPSCounter> {
  friend class Singleton<FPSCounter>;
  
  // last looping time
  double lastTime = 0;
  // frame count in 1 sec.
  int nbFrames = 0;
  
public:
  void initialize(double);
  void update(double);
  
private:
  FPSCounter();
};

NS_END2

#endif /* FPSCounter_h */
