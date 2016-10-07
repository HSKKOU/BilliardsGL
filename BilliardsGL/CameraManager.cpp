//
//  CameraManager.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/26.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "CameraManager.hpp"

CameraManager::CameraManager() { /* do nothing */ }

void CameraManager::initialize() {  }

CameraController* CameraManager::getCamera() const { return cameraCtrls[0]; }
CameraController* CameraManager::getCamera(const int index) const { return cameraCtrls[index]; }

void CameraManager::addCamera(CameraController *ctrl) { cameraCtrls.push_back(ctrl); }
