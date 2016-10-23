//
//  SceneBase.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/20.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "SceneBase.hpp"

NS_ENGINE

SceneBase::SceneBase() : bgColor(Color::one()) { /* do nothing */ }
SceneBase::SceneBase(Color c) : bgColor(c) { /* do nothing */ }
SceneBase::~SceneBase() { /* do nothing */ }

void SceneBase::start() {
  
}

void SceneBase::update() {
  
}

void SceneBase::setBackground(Color c) { bgColor = c; }

NS_END
