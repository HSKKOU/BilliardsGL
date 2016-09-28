//
//  CameraController.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/26.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "CameraController.hpp"

CameraController::CameraController(Vector3D _pos, Vector3D _dir, Vector3D _up)
: Base3D(_pos)
, direction(_dir)
, upDir(_up)
{
  
}

CameraController::~CameraController() {
  /* do nothing */
}