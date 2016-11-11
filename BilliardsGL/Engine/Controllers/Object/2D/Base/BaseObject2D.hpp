//
//  BaseObject2D.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/11.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef BaseObject2D_hpp
#define BaseObject2D_hpp

#include <vector>

#include "Base2D.h"
#include "BaseModel2D.hpp"
#include "ObjectBehavior.hpp"

US_NS_ENGINE_MODEL

NS_ENGINE

class BaseObject2D : public Base2D, public ObjectBehavior {
protected:
  std::vector<BaseModel2D*> modelList;
  
public:
  BaseObject2D();
  BaseObject2D(Point2D p);
  virtual ~BaseObject2D();
  
  void virtual awake();
  void virtual start();
  void virtual update(GLfloat deltaTime);
  void virtual lateUpdate(GLfloat deltaTime);
  void virtual draw();
  void virtual destroy();  
};

NS_END

#endif /* BaseObject2D_hpp */
