//
//  SceneFactory.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/11.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef SceneFactory_hpp
#define SceneFactory_hpp

#include "Scenes.h"

#include "SceneBase.hpp"

NS_ENGINE_SCENE

class SceneFactory {
public:
  static SceneBase* initializeScene(EScene scene);
};

NS_END2

#endif /* SceneFactory_hpp */
