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
  CameraController camera0 = CameraController(Vector3D::back()*10.0, Vector3D::forward()*1.0);
  addCamera(camera0);
}

CameraController CameraManager::getCamera() { return cameraCtrls[0]; }
CameraController CameraManager::getCamera(int index) { return cameraCtrls[index]; }

void CameraManager::addCamera(CameraController &ctrl) { cameraCtrls.push_back(ctrl); }