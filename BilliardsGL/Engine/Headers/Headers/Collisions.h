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
  Point3D position;
  Vector3D normal;
  Quad(Point3D _p, Vector3D _n) : position(_p), normal(_n) { /* do nothing */ }
};

NS_END

#endif /* Collisions_h */
