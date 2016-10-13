//
//  Sphere.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/07.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef Sphere_hpp
#define Sphere_hpp

#include "BaseObject3D.hpp"

class Sphere : public BaseObject3D {
  GLfloat radius;
  
public:
  Sphere(const Vector3D _center, const GLfloat _radius, const int _slices, const int _stacks);
  virtual ~Sphere();
  virtual void draw();
  
private:
  void setVPos(GLfloat *vPos, float ast, float asl);
};

#endif /* Sphere_hpp */
