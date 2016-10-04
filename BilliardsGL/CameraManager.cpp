//
//  CameraManager.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/26.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "CameraManager.hpp"

CameraManager::CameraManager() { /* do nothing */ }

void CameraManager::initialize() {
  // set main camera
  CameraController *camera0 = new CameraController(Vector3D(0.1,0.2,10.3), Vector3D(0.0,0.0,0.0), Vector3D(0.7,1.8,0.9));
  addCamera(camera0);
}

CameraController* CameraManager::getCamera() { return cameraCtrls[0]; }
CameraController* CameraManager::getCamera(int index) { return cameraCtrls[index]; }

void CameraManager::addCamera(CameraController *ctrl) { cameraCtrls.push_back(ctrl); }
