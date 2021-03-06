//
//  Cube.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/25.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef Cube_hpp
#define Cube_hpp

#include "BaseModel3D.hpp"

NS_ENGINE_MODEL

class Cube : public BaseModel3D {
  
protected:
  Vector3D size;
  
public:
  Cube(const Vector3D _center, const Vector3D _size);
  virtual ~Cube();
};

NS_END2

#endif /* Cube_hpp */
