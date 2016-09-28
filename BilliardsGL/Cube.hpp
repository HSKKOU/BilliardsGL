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
  GLfloat color[6*2*3][3];
  
public:
  CubeModel(const Vector3D _center, Vector3D _size) : center(_center), size(_size/2.0f) {
    const GLfloat pos[6*2*3][3] = {
      // front
      { center.x-size.x, center.y-size.y, center.z-size.z },
      { center.x+size.x, center.y-size.y, center.z-size.z },
      { center.x+size.x, center.y+size.y, center.z-size.z },
      { center.x+size.x, center.y+size.y, center.z-size.z },
      { center.x-size.x, center.y+size.y, center.z-size.z },
      { center.x-size.x, center.y-size.y, center.z-size.z },

      // back
      { center.x+size.x, center.y+size.y, center.z+size.z },
      { center.x+size.x, center.y-size.y, center.z+size.z },
      { center.x-size.x, center.y-size.y, center.z+size.z },
      { center.x-size.x, center.y-size.y, center.z+size.z },
      { center.x-size.x, center.y+size.y, center.z+size.z },
      { center.x+size.x, center.y+size.y, center.z+size.z },

      // right
      { center.x+size.x, center.y-size.y, center.z-size.z },
      { center.x+size.x, center.y-size.y, center.z+size.z },
      { center.x+size.x, center.y+size.y, center.z+size.z },
      { center.x+size.x, center.y+size.y, center.z+size.z },
      { center.x+size.x, center.y+size.y, center.z-size.z },
      { center.x+size.x, center.y-size.y, center.z-size.z },

      // left
      { center.x-size.x, center.y+size.y, center.z+size.z },
      { center.x-size.x, center.y-size.y, center.z+size.z },
      { center.x-size.x, center.y-size.y, center.z-size.z },
      { center.x-size.x, center.y-size.y, center.z-size.z },
      { center.x-size.x, center.y+size.y, center.z-size.z },
      { center.x-size.x, center.y+size.y, center.z+size.z },

      // up
      { center.x-size.x, center.y+size.y, center.z-size.z },
      { center.x+size.x, center.y+size.y, center.z-size.z },
      { center.x+size.x, center.y+size.y, center.z+size.z },
      { center.x+size.x, center.y+size.y, center.z+size.z },
      { center.x-size.x, center.y+size.y, center.z+size.z },
      { center.x-size.x, center.y+size.y, center.z-size.z },

      // down
      { center.x+size.x, center.y-size.y, center.z+size.z },
      { center.x+size.x, center.y-size.y, center.z-size.z },
      { center.x-size.x, center.y-size.y, center.z-size.z },
      { center.x-size.x, center.y-size.y, center.z-size.z },
      { center.x-size.x, center.y-size.y, center.z+size.z },
      { center.x+size.x, center.y-size.y, center.z+size.z },
    };
    
    initializeModel(pos, sizeof(pos)/sizeof(pos[0]));
    
    srand(time(0));
    for (int i=0; i<6*2*3; i++) {
      for (int j=0; j<3; j++) {
        GLfloat rnd = (GLfloat)rand() / RAND_MAX;
//        std::cout << rnd << std::endl;
        color[i][j] = rnd;
      }
    }
    
    GLuint colorBuffer;
    glGenBuffers(1, &colorBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(color)/sizeof(color[0]), color, GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
    
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
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
