//
//  BoardController.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/13.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "BoardController.hpp"

NS_GAME

BoardController::BoardController(Transform t)
: Engine::Base3D(t)
{ /* do nothing */ }

BoardController::~BoardController() {
  for (CubeRigidObject3D* elem : stageCubeList) {
    delete elem;
    elem = nullptr;
  }
  stageCubeList.clear();
}


void BoardController::setupStage() {
  // TODO: create stage objects
  CubeRigidObject3D* floor = createFloor();
  stageCubeList.emplace_back(floor);
  (ObjectManager::instance()).registerObject(floor);
}

CubeRigidObject3D* BoardController::createFloor() {
  Transform trsf = transform;
  trsf.position = Vector3D::down()*2.0f;
  Vector3D size = Vector3D(28.0f, 1.0f, 50.0f);
  RigidBody rig = RigidBody(1.0f, new CubeCollider(Transform::identity(), size));
  Surface surf = Surface(ETex::Ball00, Color(0.27f, 0.53f, 0.13f, 1.0f));
  CubeRigidObject3D* floor = new CubeRigidObject3D(trsf, size, rig, surf);
  return floor;
}

NS_END
