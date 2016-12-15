//
//  State.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/12/15.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "State.hpp"

#include "GameManager.hpp"

NS_ENGINE_UTIL

template<class T> State<T>::State(T* _owner) : owner(_owner) { /* do nothing */ }
template<class T> State<T>::~State() { owner = nullptr; }

template<class T> void State<T>::enter() { /* do nothing */ }
template<class T> void State<T>::execute(GLfloat deltaTime) { /* do nothing */ }
template<class T> void State<T>::exit() { /* do nothing */ }


template class State<Game::GameManager>;

NS_END2
