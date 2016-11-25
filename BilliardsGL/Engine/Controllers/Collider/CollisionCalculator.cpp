//
//  CollisionCalculator.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/09.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "CollisionCalculator.hpp"

NS_ENGINE

bool CollisionCalculator::collideObjects(BaseRigidObject3D* obj1, BaseRigidObject3D* obj2) {
  COL_MASK col1Mask = obj1->getCollider3D()->getColliderType();
  COL_MASK col2Mask = obj2->getCollider3D()->getColliderType();
  
  COL_MASK colsMask = col1Mask | col2Mask;

  switch(colsMask) {
    case COL_TYPE::SPHERE | COL_TYPE::CUBE: {
      SphereRigidObject3D* sRig = static_cast<SphereRigidObject3D*>(obj1);
      CubeRigidObject3D* cRig = static_cast<CubeRigidObject3D*>(obj2);
      if (col1Mask != COL_TYPE::SPHERE) { sRig = static_cast<SphereRigidObject3D*>(obj2); cRig = static_cast<CubeRigidObject3D*>(obj1); }
      
      if (isCollidedBetweenSphereAndCube(sRig, cRig)) {
        calcCollidedVelocityBetweenSphereAndCube(sRig, cRig);
        return true;
      }}
      break;
    case COL_TYPE::SPHERE: {
      SphereRigidObject3D* rig1 = static_cast<SphereRigidObject3D*>(obj1);
      SphereRigidObject3D* rig2 = static_cast<SphereRigidObject3D*>(obj2);
      if (isCollidedBetweenSphere(rig1, rig2)) {
        calcCollidedVelocityBetweenSphere(rig1, rig2);
        return true;
      }}
      break;
    case COL_TYPE::CUBE:
      break;
    default:
      break;
  }
      
  return false;
}


bool CollisionCalculator::isCollidedBetweenSphereAndCube(SphereRigidObject3D* sRig, CubeRigidObject3D* cRig) {
  return cRig->isCollidedWithSphere(sRig);
}
bool CollisionCalculator::isCollidedBetweenSphere(SphereRigidObject3D* rig1, SphereRigidObject3D* rig2) {
  Vector3D objectCenterDistVec
  = (rig1->getPosition() + rig1->getCollider3D()->getPosition()) - (rig2->getPosition() + rig2->getCollider3D()->getPosition());
  GLfloat objectDist = objectCenterDistVec.length() - (rig1->getCollider3D()->getRadius() + rig2->getCollider3D()->getRadius());
  return objectDist <= COL_DETECT_EPS;
}
bool CollisionCalculator::isCollidedBetweenCube(CubeRigidObject3D* rig1, CubeRigidObject3D* rig2) {
  // TODO:
  return false;
}



void CollisionCalculator::calcCollidedVelocityBetweenSphere(SphereRigidObject3D* rig1, SphereRigidObject3D* rig2) {
  Vector3D collisionAxis =
  rig1->getPosition() + rig1->getCollider3D()->getPosition()
  - rig2->getPosition() + rig2->getCollider3D()->getPosition();
  
  GLfloat dentLength =
  rig1->getCollider3D()->getRadius()
  + rig2->getCollider3D()->getRadius()
  - collisionAxis.length();
  
  rig1->addForce(COL_SPRING_CST*dentLength, collisionAxis.normalize());
  rig2->addForce(COL_SPRING_CST*dentLength, collisionAxis.normalize()*-1.0f);
}

void CollisionCalculator::calcCollidedVelocityBetweenSphereAndCube(SphereRigidObject3D* sRig, CubeRigidObject3D* cRig) {
  // TODO:
}






/* Cube Collision Detectors */
bool CollisionCalculator::isCollidedWithSphereByAABBCube(SphereRigidObject3D* sRig, CubeRigidObject3D* cRig) {
  Point3D cCenter = cRig->getPosition() + cRig->getCollider3D()->getPosition();
  Vector3D cSize = cRig->getCollider3D()->getSize();
  Point3D sCenter = sRig->getPosition() + sRig->getCollider3D()->getPosition();
  GLfloat sRad = sRig->getCollider3D()->getRadius();
  for (int di=0; di<3; di++) {     // target dimension
    for (int k=1; k<=2; k++) {
      int d = (di+k)%3;  // other dimensions
      GLfloat range = cSize[d] + sRad;
      if ( (sCenter[d] < cCenter[d] - range) || (sCenter[d] > cCenter[d] + range) ) { return false; }
    }
  }
  
  return true;
}
bool CollisionCalculator::isCollidedWithSphereByOBBCube(SphereRigidObject3D* sRig, CubeRigidObject3D* cRig) { return false; }

NS_END
