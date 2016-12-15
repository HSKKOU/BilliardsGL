//
//  State.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/12/15.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "State.hpp"

NS_ENGINE_UTIL

template<class T> State<T>::State(T* _owner) : owner(_owner) { /* do nothing */ }
template<class T> State<T>::~State() { owner = nullptr; }

NS_END2
