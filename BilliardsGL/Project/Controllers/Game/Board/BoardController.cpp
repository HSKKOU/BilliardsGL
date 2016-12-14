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
  Point3D wPosNS = Vector3D(0.0f, 0.0f, 52.0f);
  Point3D wPosWS = Vector3D(30.0f, 0.0f, 25.0f);
  Vector3D wSizeNS = Vector3D(26.0f, 1.0f, 2.0f);
  Vector3D wSizeWE = Vector3D(2.0f, 1.0f, 23.0f);
  // walls
  CubeRigidObject3D* wallN  = createWall(wPosNS , wSizeNS);
  CubeRigidObject3D* wallS  = createWall(wPosNS*-1.0f    , wSizeNS);
  CubeRigidObject3D* wallWN = createWall(wPosWS*(Vector3D::left()+Vector3D::forward())    , wSizeWE);
  CubeRigidObject3D* wallWS = createWall(wPosWS*(Vector3D::left()+Vector3D::back())    , wSizeWE);
  CubeRigidObject3D* wallEN = createWall(wPosWS*(Vector3D::right()+Vector3D::forward())   , wSizeWE);
  CubeRigidObject3D* wallES = createWall(wPosWS*(Vector3D::right()+Vector3D::back())   , wSizeWE);
  
  // frame
  Point3D fPosTmp = Vector3D(33.0f, 0.0f, 55.0f);
  Vector3D fSizeNS = Vector3D(32.0f, 1.0f, 1.0f);
  Vector3D fSizeWE = Vector3D(1.0f, 1.0f, 56.0f);
  CubeRigidObject3D* frameN = createFrame(fPosTmp*Vector3D::forward(), fSizeNS);
  CubeRigidObject3D* frameS = createFrame(fPosTmp*Vector3D::back()   , fSizeNS);
  CubeRigidObject3D* frameW = createFrame(fPosTmp*Vector3D::left()   , fSizeWE);
  CubeRigidObject3D* frameE = createFrame(fPosTmp*Vector3D::right()  , fSizeWE);
}

CubeRigidObject3D* BoardController::createFloor() {
  Surface surf = Surface(ETex::BFloor, Color(0.27f, 0.53f, 0.13f, 1.0f));
  CubeRigidObject3D* floor = createBaseCube(Vector3D::down()*2.0f, Vector3D(28.0f, 1.0f, 50.0f), surf);
  floor->setIsRigid(false);
  (ObjectManager::instance()).registerObject(floor);
  return floor;
}

CubeRigidObject3D* BoardController::createWall(Point3D position, Vector3D size) {
  Surface surf = Surface(ETex::BFloor, Color(0.27f, 0.53f, 0.13f, 1.0f));
  CubeRigidObject3D* wall = createBaseCube(position, size, surf);
  wallList.emplace_back(wall);
  (ObjectManager::instance()).registerObject(wall);
  return wall;
}

CubeRigidObject3D* BoardController::createFrame(Point3D position, Vector3D size) {
  CubeRigidObject3D* frame = createWall(position, size);
  frame->setIsRigid(false);
  return frame;
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
