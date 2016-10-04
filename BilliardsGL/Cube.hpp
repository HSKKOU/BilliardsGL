//
//  Cube.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/25.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef Cube_hpp
#define Cube_hpp

#include "BaseObject3D.hpp"

#include "ShaderLoader.hpp"

class Cube : public BaseObject3D {
  
protected:
  Vector3D size;
  
public:
  Cube(const Vector3D _center, const Vector3D _size);
  virtual ~Cube();
  virtual void loadShaderProgram();
  virtual void draw();
};

#endif /* Cube_hpp */
