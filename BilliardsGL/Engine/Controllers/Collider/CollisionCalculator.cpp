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
//  return cRig->isCollidedWithSphere(sRig);
  return isCollidedWithSphereByAABBCube(sRig, cRig);
//  return isCollidedWithSphereByOBBCube(sRig, cRig);
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
  Point3D cubePos = cRig->getColliderPos();
  Vector3D cubeSize = cRig->getCollider3D()->getSize();
  Point3D spherePos = sRig->getColliderPos();
  
  Quad colPlane = createCollisionPlaneBetweenPointAndCube(spherePos, cubePos, cubeSize);
  
  Vector3D sphereVel = sRig->getVelocity();
  Vector3D vN = colPlane.normal * colPlane.normal.dot(sphereVel);
  
  Vector3D force = vN * -(1.0+1.0);
  
  sRig->addForce(force.length(), force.normalize());
  cRig->addForce(force.length(), force.normalize()*-1.0f);
  
  return;
}

Quad CollisionCalculator::createCollisionPlaneBetweenPointAndCube(Point3D point, Point3D cubeCenter, Vector3D cubeSize) {
  Vector3D relDist = point - cubeCenter;
  
  Vector3D colPlaneCenter = relDist.sign() * cubeSize;
  Vector3D colPlaneNormal = point - colPlaneCenter;
  Quad colPlane = Quad(colPlaneCenter, colPlaneNormal);
  for (int di=0; di<3; di++) {     // target dimension di:(0->x, 1->y, 2->z)
    if (fabsf(relDist[di]) <= cubeSize[di]) {
      colPlane.position[di] = 0.0f;
      colPlane.normal[di] = 0.0f;
    }
  }
  
  colPlane.normal = colPlane.normal.normalize();
  
  return colPlane;
}




/* Cube Collision Detectors */
bool CollisionCalculator::isCollidedWithSphereByAABBCube(SphereRigidObject3D* sRig, CubeRigidObject3D* cRig) {
  Point3D cCenter = cRig->getColliderPos();
  Vector3D cSize = cRig->getCollider3D()->getSize();
  Point3D sCenter = sRig->getColliderPos();
  GLfloat sRad = sRig->getCollider3D()->getRadius();
  for (int di=0; di<3; di++) {     // target dimension di:(0->x, 1->y, 2->z)
    GLfloat range = cSize[di] + sRad;
    if ( (sCenter[di] < cCenter[di] - range) || (sCenter[di] > cCenter[di] + range) ) { return false; }
  }
  
  return true;
}
bool CollisionCalculator::isCollidedWithSphereByOBBCube(SphereRigidObject3D* sRig, CubeRigidObject3D* cRig) {
  return false;
}

NS_END
