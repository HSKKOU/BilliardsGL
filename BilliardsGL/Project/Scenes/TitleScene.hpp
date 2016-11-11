//
//  TitleScene.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/11.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef TitleScene_hpp
#define TitleScene_hpp

#include "SceneBase.hpp"

US_NS_ENGINE

NS_GAME

class TitleScene : public Scene::SceneBase {
  int updateCnt;
  
public:
  TitleScene();
  virtual ~TitleScene();
  
  virtual void enter();
  virtual void exit();
  virtual void update(GLfloat deltaTime);
};

NS_END

#endif /* TitleScene_hpp */
