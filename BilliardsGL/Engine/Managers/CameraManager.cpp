//
//  CameraManager.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/26.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "CameraManager.hpp"

NS_ENGINE

CameraManager::CameraManager() { /* do nothing */ }
CameraManager::~CameraManager() { SAFE_DELETE_VECTOR(cameraCtrls, CameraControllerBase); }

CameraControllerBase* CameraManager::getMainCamera() const { return cameraCtrls[0]; }
CameraControllerBase* CameraManager::getCamera(const int index) const { return cameraCtrls[index]; }

void CameraManager::addCamera(CameraControllerBase *ctrl) { cameraCtrls.push_back(ctrl); }

NS_END
