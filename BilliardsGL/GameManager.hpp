//
//  GameManager.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/15.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef GameManager_hpp
#define GameManager_hpp

#include "GlobalHeader.h"
#include "Singleton.h"

#include "Window.hpp"
#include "FPSCounter.hpp"

class GameManager : public Singleton<GameManager> {
  friend class Singleton<GameManager>;
  
  Window window;
  
public:
  void initialize();
  void startMainLoop();
  
protected:
  GameManager();
  
private:
  void mainLoop();

};

#endif /* GameManager_hpp */
