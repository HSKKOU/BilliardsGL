//
//  BallManager.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/14.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "BallManager.hpp"

NS_GAME

BallManager::BallManager() { /* do nothing */ }
BallManager::~BallManager() {
  delete whiteBall;
  whiteBall = nullptr;
  
  for (BallController* ball : ballList) {
    delete ball;
    ball = nullptr;
  }
  ballList.clear();
}


void BallManager::initialize() {
  whiteBall = new WhiteBallController(Transform::identity());
  (ObjectManager::instance()).registerObject(whiteBall);
  whiteBall->translateTo(Vector3D::back()*30.0f);
  
  for (int i=0; i<BALL_NUM; i++) {
    BallController* ball = new BallController(Transform::identity(), i+1);
    (ObjectManager::instance()).registerObject(ball);
    
    float row = ceilf((sqrtf(1.0 + 8.0*(i+1)) - 1.0f) / 2.0f);
    int sumAtLastRow = (int)((row*(row-1))/2.0f);
    float posX = 1.1f * (2.0f*((i+1)-sumAtLastRow)-row-1);
    float posZ = (row-1) * 1.75033f * 1.1f;
    ball->translateTo(Vector3D(posX, 0.0f, -posZ));
    ball->rotation(Quaternion(Vector3D(1.0f, 0.0f, 0.0f).normalize(), -M_PI/2.0f));
    
    ballList.emplace_back(ball);
  }
}

void BallManager::shotWhiteBall() {
  whiteBall->addForce(35.0f, Vector3D::forward());
}

NS_END
