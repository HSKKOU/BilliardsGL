//
//  CubeCollider.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/13.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef CubeCollider_hpp
#define CubeCollider_hpp

#include "ColliderBase3D.hpp"

NS_ENGINE

class CubeCollider : public ColliderBase3D {
protected:
  Vector3D size;
  
public:
  CubeCollider(Transform r, Vector3D s);
  CubeCollider(Vector3D s);
  virtual ~CubeCollider();
  
  Vector3D getSize() const;
};

NS_END

#endif /* CubeCollider_hpp */
