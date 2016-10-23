//
//  ObjectBehavior.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/23.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef ObjectBehavior_hpp
#define ObjectBehavior_hpp

#include "GlobalHeader.h"

NS_ENGINE

class ObjectBehavior {
  
public:
  ObjectBehavior();
  virtual ~ObjectBehavior();
  
  void virtual awake();
  void virtual start();
  void virtual update();
  void virtual lateUpdate();
  void virtual draw();
};

NS_END

#endif /* ObjectBehavior_hpp */
