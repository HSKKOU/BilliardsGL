//
//  WhiteBallController.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/23.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "WhiteBallController.hpp"

NS_GAME

WhiteBallController::WhiteBallController(Transform t) : Game::BallController(t) { /* do nothing */ }
WhiteBallController::~WhiteBallController() { /* do nothing */ }

void WhiteBallController::awake() {
  createBall(ETex::Ball00);
}

void WhiteBallController::start() {
  
}

void WhiteBallController::update() {
}

NS_END
