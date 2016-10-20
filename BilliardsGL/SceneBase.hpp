//
//  SceneBase.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/20.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef SceneBase_hpp
#define SceneBase_hpp

#include "GlobalHeader.h"

NS_ENGINE

class SceneBase {
  
public:
  SceneBase();
  virtual ~SceneBase();
  
  virtual void start();
  virtual void update();
};

NS_END

#endif /* SceneBase_hpp */
