//
//  main.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/15.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include <cstdlib>

#include "GlobalHeader.h"
#include "GameManager.hpp"

int main(int argc, const char * argv[]) {
  
  // GameManager Initialized
  GameManager &gameManager = GameManager::instance();
  gameManager.initialize();  

  // Start Game
  gameManager.startMainLoop();
}
