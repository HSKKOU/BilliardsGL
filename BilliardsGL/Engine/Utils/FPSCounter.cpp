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

void FPSCounter::setShowFlag(bool isShowFlag) { isShowFPS = isShowFlag; }

void FPSCounter::start(double startTime) {
  // set initial time
  lastTime = startTime;
  currentFPS = 0.0;
}

double FPSCounter::update(double currentTime) {
  double deltaTime = currentTime - lastTime;
  
  currentFPS = 1.0/deltaTime;

  if (isShowFPS) {
    std::cout << "= fps =======================" << std::endl;
    std::cout << deltaTime*1000.0 << " ms/frame" << std::endl;
    std::cout << currentFPS << " fps" << std::endl;
    std::cout << "=============================" << std::endl;
  }
  
  lastTime = currentTime;
  return deltaTime;
}

double FPSCounter::getFPS() const { return currentFPS; }

bool FPSCounter::isStable() const { return std::abs(currentFPS-60.0) < 5.0; }

NS_END2
