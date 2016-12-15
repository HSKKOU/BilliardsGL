//
//  StateMachine.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/12/15.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "StateMachine.hpp"

NS_ENGINE_UTIL

template<class T> StateMachine<T>::StateMachine() { /* do nothing */ }
template<class T> StateMachine<T>::~StateMachine() { stateList.clear(); }

template<class T> void StateMachine<T>::addState(State<T>* state) { stateList.emplace_back(state); }

template<class T> void StateMachine<T>::changeState(StateId sId) {
  if (sId < 0 || sId >= stateList.size()) { return; }
  State<T> nextState = stateList[sId];
  if (nextState == nullptr) { return; }

  if (currentState != nullptr) { currentState->exit(); }
  currentState = nextState;
  currentState->enter();
}

template <class T> void StateMachine<T>::update(GLfloat deltaTime) {
  if (currentState == nullptr) { return; }
  currentState->execute(deltaTime);
}


NS_END2
