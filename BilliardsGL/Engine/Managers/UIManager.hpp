//
//  UIManager.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/13.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef UIManager_hpp
#define UIManager_hpp

#include "Singleton.h"

US_NS_ENGINE_UTIL

NS_ENGINE

class UIManager : public Singleton<UIManager> {
  friend class Singleton<UIManager>;
  
public:
  virtual ~UIManager();
  void initialize();
  
private:
  UIManager();
};

NS_END

#endif /* UIManager_hpp */
