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

class FPSCounter : public Singleton<FPSCounter> {
  friend class Singleton<FPSCounter>;
  
  double lastTime = 0;
  int nbFrames = 0;
  
public:
  void initialize(double);
  void update(double);
  
private:
  FPSCounter();
};

#endif /* FPSCounter_h */
