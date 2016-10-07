//
//  ObjectFactory.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/07.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "ObjectFactory.hpp"

BaseObject3D* ObjectFactory::instantiateObject(ObjectType type) {
  return new Cube(Vector3D::zero(), Vector3D::one());
}
