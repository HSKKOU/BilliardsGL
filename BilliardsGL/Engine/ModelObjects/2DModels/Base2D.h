//
//  Base2D.h
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/11.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef Base2D_h
#define Base2D_h

NS_ENGINE

class Base2D {
  
protected:
  
  
public:
  Base2D(Vector2D t) { /* do nothing */ }
  virtual ~Base2D() { /* do nothing */ }
  
  Vector3D getPosition() const { return transform.position; }
  Vector4D getPosition4D() const { return Vector4D(transform.position,1.0); }
  void setPosition(const Vector3D pos) { transform.position = pos; }
  
  virtual void setTransform(Transform trsf) { transform = trsf; }
  
  virtual void translateTo(Vector3D dest) { transform.position = dest; }
  virtual void rotation(Quaternion rot) { transform.rotation = rot; }
  virtual void scale(Vector3D scl) { transform.scale = scl; }
  
  virtual void translate(Vector3D delta) { transform.position += delta; }
  virtual void rotate(Quaternion rot) { transform.rotation *= rot; }
};

NS_END

#endif /* Base2D_h */
