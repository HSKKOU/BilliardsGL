//
//  Square.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/23.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef Square_hpp
#define Square_hpp

#include "BaseObject.hpp"

struct SquareModel : public BaseModel {
  GLfloat x, y, w, h;
  
public:
  SquareModel(GLfloat _x, GLfloat _y, GLfloat _w, GLfloat _h): x(_x), y(_y), w(_w), h(_h) {
    GLfloat pos[4][2] = {
      { x  , y   },
      { x+w, y   },
      { x+w, y+h },
      { x  , y+h }
    };
    initializeModel(pos, sizeof(pos)/sizeof(pos[0]));
  }
};


class Square {
  SquareModel square;
  
public:
  Square(GLfloat x, GLfloat y, GLfloat w, GLfloat h);
  virtual ~Square();
  void draw();
};

#endif /* Square_hpp */
