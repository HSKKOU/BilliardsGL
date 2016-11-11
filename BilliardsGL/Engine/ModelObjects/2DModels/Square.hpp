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

NS_ENGINE_MODEL

class Square : public BaseModel2D {

protected:
  Vector2D size;

public:
  Square(Point2D _center, Vector2D _size);
  virtual ~Square();
};

NS_END2

#endif /* Square_hpp */
