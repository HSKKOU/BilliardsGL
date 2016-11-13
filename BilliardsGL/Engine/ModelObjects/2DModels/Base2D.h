//
//  Base2D.h
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/11.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef Base2D_h
#define Base2D_h

#include "Matrix.h"

NS_ENGINE

class Base2D {
  
protected:
  Point2D position;
  
public:
  Base2D() : Base2D(Point2D::zero()) { /* do nothing */ }
  Base2D(Point2D p) : position(p) { /* do nothing */ }
  virtual ~Base2D() { /* do nothing */ }
  
  Vector2D getPosition() const { return position; }
  Vector3D getPosition3D() const { return Vector3D(position.x, position.y, 1.0); }
  void setPosition(const Vector2D pos) { position = pos; }
  
  virtual void translateTo(Vector2D dest) { position = dest; }
  virtual void translate(Vector2D delta) { position += delta; }
};

NS_END

#endif /* Base2D_h */
