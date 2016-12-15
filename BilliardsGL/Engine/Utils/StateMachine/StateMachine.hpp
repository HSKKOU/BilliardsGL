//
//  StateMachine.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/12/15.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef StateMachine_hpp
#define StateMachine_hpp

#include "GlobalHeader.h"
#include <vector>

#include "State.hpp"

NS_ENGINE_UTIL

typedef int StateId;

template<class T>
class StateMachine {
protected:
  std::vector<State<T>*> stateList;
  State<T>* currentState;
  
public:
  StateMachine();
  virtual ~StateMachine();
  
  void addState(State<T>* state);
  void changeState(StateId sId);
  
  void update(GLfloat deltaTime);
};

NS_END2

#endif /* StateMachine_hpp */
