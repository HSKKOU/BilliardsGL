//
//  FPSCounter.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/23.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "FPSCounter.hpp"

NS_ENGINE_UTIL

FPSCounter::FPSCounter() { /* do nothing */ }

void FPSCounter::initialize(double startTime) {
  // set initial time
  lastTime = startTime;
}

void FPSCounter::update(double currentTime) {
  // increment fps counter
  nbFrames++;
  
  // show fps in 1sec.
  if (currentTime - lastTime >= 1.0) {
//    std::cout << "= fps =======================" << std::endl;
//    std::cout << 1000.0/double(nbFrames) << " ms/frame" << std::endl;
//    std::cout << nbFrames << " fps" << std::endl;
//    std::cout << "=============================" << std::endl;
    nbFrames = 0;
    lastTime += 1.0;
  }
}

NS_END2
