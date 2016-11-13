//
//  BaseObject3D.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/22.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef BaseObject3D_hpp
#define BaseObject3D_hpp

#include <vector>

#include "Base3D.h"
#include "BaseModel3D.hpp"
#include "ObjectBehavior.hpp"

US_NS_ENGINE_MODEL

NS_ENGINE

class BaseObject3D : public Base3D, public ObjectBehavior {
protected:
  std::vector<BaseModel3D*> modelList;
  
public:
  BaseObject3D();
  BaseObject3D(Transform t);
  virtual ~BaseObject3D();
    
  virtual void awake();
  virtual void start();
  virtual void update(GLfloat deltaTime);
  virtual void lateUpdate(GLfloat deltaTime);
  virtual void draw();
  virtual void destroy();
  
  virtual void setTransform(Transform trsf);
  
  virtual void translateTo(Vector3D dest);
  virtual void rotation(Quaternion rot);
  virtual void scale(Vector3D scl);
  
  virtual void translate(Vector3D delta);
  virtual void rotate(Quaternion rot);
};

NS_END

#endif /* BaseObject3D_hpp */
