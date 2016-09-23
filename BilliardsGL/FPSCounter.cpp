//
//  FPSCounter.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/23.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "FPSCounter.hpp"

FPSCounter::FPSCounter() { /* do nothing */ }

void FPSCounter::initialize(double startTime) {
  lastTime = startTime;
}

void FPSCounter::update(double currentTime) {
  // calc fps
  nbFrames++;
  if (currentTime - lastTime >= 1.0) {
//    std::cout << 1000.0/double(nbFrames) << " ms/frame" << std::endl;
    nbFrames = 0;
    lastTime += 1.0;
  }
}
