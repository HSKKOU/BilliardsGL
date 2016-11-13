//
//  SquareObject2D.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/13.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef SquareObject2D_hpp
#define SquareObject2D_hpp

#include "BaseObject2D.hpp"

NS_ENGINE

class SquareObject2D : public BaseObject2D {
  Vector2D size;
  
public:
  SquareObject2D(Point2D p, Vector2D s);
  virtual ~SquareObject2D();
};

NS_END

#endif /* SquareObject2D_hpp */
