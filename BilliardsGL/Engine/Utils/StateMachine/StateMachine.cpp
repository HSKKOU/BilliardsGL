//
//  StateMachine.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/12/15.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "StateMachine.hpp"

#include "GameManager.hpp"

NS_ENGINE_UTIL

template<class T> StateMachine<T>::StateMachine() : currentStateId(-1) { /* do nothing */ }
template<class T> StateMachine<T>::~StateMachine() { stateList.clear(); }

template<class T> void StateMachine<T>::addState(State<T>* state) { stateList.emplace_back(state); }

template<class T> void StateMachine<T>::changeState(StateId sId) {
  if (sId < 0 || sId >= stateList.size()) { return; }
  State<T>* nextState = stateList[sId];
  if (nextState == nullptr) { return; }

  if (currentState != nullptr && sId != 0) { currentState->exit(); }
  currentState = nextState;
  currentStateId = sId;
  currentState->enter();
}

template <class T> StateId StateMachine<T>::getCurrentStateId() { return currentStateId; }

template <class T> void StateMachine<T>::update(GLfloat deltaTime) {
  if (currentState == nullptr) { return; }
  currentState->execute(deltaTime);
}


template class StateMachine<Game::GameManager>;


NS_END2
