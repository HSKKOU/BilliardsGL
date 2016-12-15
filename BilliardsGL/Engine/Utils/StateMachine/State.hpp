//
//  State.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/12/15.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef State_hpp
#define State_hpp

#include "GlobalHeader.h"

NS_ENGINE_UTIL

template<class T>
class State {
protected:
  T* owner;
  
public:
  State(T* _owner);
  virtual ~State();
  
  virtual void enter();
  virtual void execute(GLfloat deltaTime);
  virtual void exit();
};

NS_END2

#endif /* State_hpp */
