//
//  Square.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/23.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef Square_hpp
#define Square_hpp

#include "BaseModel2D.hpp"

#include "ShaderLoader.hpp"

NS_ENGINE_MODEL

struct SquareModel : public BaseModel2D {
  GLfloat x, y, w, h;
  
public:
  SquareModel(GLfloat _x, GLfloat _y, GLfloat _w, GLfloat _h): x(_x), y(_y), w(_w), h(_h) {
    const GLfloat pos[6][2] = {
      { x  , y   },
      { x+w, y   },
      { x+w, y+h },
      { x  , y   },
      { x  , y+h },
      { x+w, y+h }
    };
    initializeModel(pos, sizeof(pos)/sizeof(pos[0]));
  }
};


class Square : public BaseModel2D {
  SquareModel square;

public:
  Square(GLfloat x, GLfloat y, GLfloat w, GLfloat h);
  virtual ~Square();
  virtual void draw();
};

NS_END2

#endif /* Square_hpp */
