//
//  main.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/15.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include <cstdlib>

#include "GlobalHeader.h"
#include "GameEngineManager.hpp"

using namespace Engine;

int main(int argc, const char * argv[]) {
  
  // GameEngineManager Initialized
  GameEngineManager &gameEngineManager = GameEngineManager::instance();
  gameEngineManager.initialize();

  // Start Game Engine
  gameEngineManager.startMainLoop();
}
