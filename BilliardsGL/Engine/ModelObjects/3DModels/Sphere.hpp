//
//  Sphere.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/07.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef Sphere_hpp
#define Sphere_hpp

#include "BaseModel3D.hpp"

NS_ENGINE_MODEL

class Sphere : public BaseModel3D {
  GLfloat radius;
  
public:
  Sphere(const Vector3D _center, const GLfloat _radius, const int _slices, const int _stacks);
  virtual ~Sphere();
  
private:
  void setVPos(GLfloat *vPos, int ist, int jsl, int stk, int slc, float ast, float asl);
};

NS_END2

#endif /* Sphere_hpp */
