//
//  SceneBase.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/20.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef SceneBase_hpp
#define SceneBase_hpp

#include "GlobalHeader.h"
#include "Vector4D.hpp"

#include "ObjectManager.hpp"

NS_ENGINE_SCENE

class SceneBase {
  Color bgColor;
  
public:
  SceneBase();
  SceneBase(Color c);
  virtual ~SceneBase();
  
  virtual void enter();
  virtual void exit();
  
  virtual void update(GLfloat deltaTime);
  
  virtual void setBackground(Color c);
};

NS_END2

#endif /* SceneBase_hpp */
