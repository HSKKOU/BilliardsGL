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
#include "Vector3D.h"

class Base3D {
  
protected:
  Vector3D position;
  
public:
  Base3D(Vector3D pos) : position(pos) { /* do nothing */ }
  virtual ~Base3D() { /* do nothing */ }
  
  Vector3D getPosition() { return position; }
  void setPosition(Vector3D pos) { position = pos; }
};

#endif /* Base3D_h */
