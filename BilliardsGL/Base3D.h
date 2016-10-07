//
//  Base3D.h
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/26.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef Base3D_h
#define Base3D_h

#include "glm/glm.hpp"
#include "Matrix.h"

class Base3D {
  
protected:
  Vector3D position;
  
public:
  Base3D(Vector3D pos) : position(pos) { /* do nothing */ }
  virtual ~Base3D() { /* do nothing */ }
  
  Vector3D getPosition() const { return position; }
  Vector4D getPosition4D() const { return Vector4D(position,1.0); }
  void setPosition(const Vector3D pos) { position = pos; }
};

#endif /* Base3D_h */
