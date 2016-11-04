//
//  SphereCollider.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/04.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef SphereCollider_hpp
#define SphereCollider_hpp

#include "ColliderBase3D.cpp"

NS_ENGINE

class SphereCollider : public ColliderBase3D {
protected:
  GLfloat radius;
  
public:
  SphereCollider(GLfloat r);
  virtual ~SphereCollider();
};

NS_END

#endif /* SphereCollider_hpp */
