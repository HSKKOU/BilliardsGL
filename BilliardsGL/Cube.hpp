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

struct CubeModel : BaseModel3D {
  Vector3D center;
  Vector3D size;
  
public:
  CubeModel(const Vector3D _center, Vector3D _size) : center(_center), size(_size/2) {
    const GLfloat pos[6*2*3][3] = {
      // front
      { center.x-size.x, center.y-size.y, center.z-size.z },
      { center.x+size.x, center.y-size.y, center.z-size.z },
      { center.x+size.x, center.y+size.y, center.z-size.z },
      { center.x-size.x, center.y-size.y, center.z-size.z },
      { center.x-size.x, center.y+size.y, center.z-size.z },
      { center.x+size.x, center.y+size.y, center.z-size.z },

      // back
      { center.x-size.x, center.y-size.y, center.z+size.z },
      { center.x+size.x, center.y-size.y, center.z+size.z },
      { center.x+size.x, center.y+size.y, center.z+size.z },
      { center.x-size.x, center.y-size.y, center.z+size.z },
      { center.x-size.x, center.y+size.y, center.z+size.z },
      { center.x+size.x, center.y+size.y, center.z+size.z },

      // right
      { center.x+size.x, center.y-size.y, center.z-size.z },
      { center.x+size.x, center.y-size.y, center.z+size.z },
      { center.x+size.x, center.y+size.y, center.z+size.z },
      { center.x+size.x, center.y-size.y, center.z-size.z },
      { center.x+size.x, center.y+size.y, center.z-size.z },
      { center.x+size.x, center.y+size.y, center.z+size.z },

      // left
      { center.x-size.x, center.y-size.y, center.z-size.z },
      { center.x-size.x, center.y-size.y, center.z+size.z },
      { center.x-size.x, center.y+size.y, center.z+size.z },
      { center.x-size.x, center.y-size.y, center.z-size.z },
      { center.x-size.x, center.y+size.y, center.z-size.z },
      { center.x-size.x, center.y+size.y, center.z+size.z },

      // up
      { center.x-size.x, center.y+size.y, center.z-size.z },
      { center.x+size.x, center.y+size.y, center.z-size.z },
      { center.x+size.x, center.y+size.y, center.z+size.z },
      { center.x-size.x, center.y+size.y, center.z-size.z },
      { center.x-size.x, center.y+size.y, center.z+size.z },
      { center.x+size.x, center.y+size.y, center.z+size.z },

      // down
      { center.x-size.x, center.y-size.y, center.z-size.z },
      { center.x+size.x, center.y-size.y, center.z-size.z },
      { center.x+size.x, center.y-size.y, center.z+size.z },
      { center.x-size.x, center.y-size.y, center.z-size.z },
      { center.x-size.x, center.y-size.y, center.z+size.z },
      { center.x+size.x, center.y-size.y, center.z+size.z },
    };
    
    initializeModel(pos, sizeof(pos)/sizeof(pos[0]));
  }
};

class Cube : BaseObject3D {
  
protected:
  CubeModel cube;
  
public:
  Cube(const Vector3D _center, const Vector3D _size);
  virtual ~Cube();
  virtual void loadShaderProgram();
  virtual void draw();
};

#endif /* Cube_hpp */
