//
//  Collisions.h
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/04.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef Collisions_h
#define Collisions_h

#include "ColliderBase3D.hpp"
#include "SphereCollider.hpp"
#include "CubeCollider.hpp"

NS_ENGINE

struct Quad {
  Point3D p;
  Vector3D n;
};

NS_END

#endif /* Collisions_h */
