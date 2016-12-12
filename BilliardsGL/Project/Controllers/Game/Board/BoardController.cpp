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
  SAFE_DELETE(floor);
  SAFE_DELETE_VECTOR(wallList, CubeRigidObject3D);
}


void BoardController::setupStage() {
  // TODO: create stage objects
  CubeRigidObject3D* floor = createFloor();
  
  // wall position, size templates
  Point3D wPosTmp = Vector3D(29.0f, 0.0f, 51.0f);
  Vector3D wSizeNS = Vector3D(28.0f, 1.0f, 1.0f);
  Vector3D wSizeWE = Vector3D(1.0f, 1.0f, 52.0f);
  // walls
  CubeRigidObject3D* wallFront = createWall(wPosTmp*Vector3D::forward() , wSizeNS);
  CubeRigidObject3D* wallBack  = createWall(wPosTmp*Vector3D::back()    , wSizeNS);
  CubeRigidObject3D* wallLeft  = createWall(wPosTmp*Vector3D::left()    , wSizeWE);
  CubeRigidObject3D* wallRight = createWall(wPosTmp*Vector3D::right()   , wSizeWE);
}

CubeRigidObject3D* BoardController::createFloor() {
  Surface surf = Surface(ETex::Ball00, Color(0.27f, 0.53f, 0.13f, 1.0f));
  CubeRigidObject3D* floor = createBaseCube(Vector3D::down()*2.0f, Vector3D(28.0f, 1.0f, 50.0f), surf);
  floor->setIsRigid(false);
  (ObjectManager::instance()).registerObject(floor);
  return floor;
}

CubeRigidObject3D* BoardController::createWall(Point3D position, Vector3D size) {
  Surface surf = Surface(ETex::Ball00, Color(0.27f, 0.53f, 0.13f, 1.0f));
  CubeRigidObject3D* wall = createBaseCube(position, size, surf);
  wallList.emplace_back(wall);
  (ObjectManager::instance()).registerObject(wall);
  return wall;
}

CubeRigidObject3D* BoardController::createBaseCube(Point3D position, Vector3D size, Surface surf) {
  Transform trsf = transform;
  trsf.position = position;
  RigidBody rig = RigidBody(1.0f);
  CubeRigidObject3D* cube = new CubeRigidObject3D(trsf, size, rig, surf);
  cube->setIsStatic(true);
  return cube;
}


NS_END
