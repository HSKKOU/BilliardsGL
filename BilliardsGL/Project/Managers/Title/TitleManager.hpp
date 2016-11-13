//
//  TitleManager.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/13.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef TitleManager_hpp
#define TitleManager_hpp

#include "BehaviorSingleton.h"

#include "ObjectManager.hpp"

#include "UI.h"

US_NS_ENGINE
US_NS_ENGINE_UTIL
US_NS_ENGINE_UI

NS_GAME

class TitleManager : public BehaviorSingleton<TitleManager> {
  friend class BehaviorSingleton<TitleManager>;
  
  // for Debug
  UIPanel* panel;
  
public:
  virtual ~TitleManager();
  void initialize();
  
  virtual void awake();
  virtual void start();
  virtual void update(GLfloat deltaTime);
  
private:
  TitleManager();
};

NS_END

#endif /* TitleManager_hpp */
