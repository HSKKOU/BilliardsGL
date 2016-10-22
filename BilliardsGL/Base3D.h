//
//  Base3D.h
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/26.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef Base3D_h
#define Base3D_h

#include "Matrix.h"
#include "Transform.hpp"

NS_ENGINE

class Base3D {
  
protected:
  Transform transform;
  
public:
  Base3D(Transform t) : transform(t) { /* do nothing */ }
  virtual ~Base3D() { /* do nothing */ }
  
  Vector3D getPosition() const { return transform.position; }
  Vector4D getPosition4D() const { return Vector4D(transform.position,1.0); }
  void setPosition(const Vector3D pos) { transform.position = pos; }
  
  virtual void translate(Vector3D dest) { transform.position = dest; }
  virtual void rotation(Quaternion rot) { transform.rotation = rot; }
  virtual void scale(Vector3D scl) { transform.scale = scl; }
  
  virtual void rotate(Quaternion rot) { transform.rotation *= rot; }
};

NS_END

#endif /* Base3D_h */
