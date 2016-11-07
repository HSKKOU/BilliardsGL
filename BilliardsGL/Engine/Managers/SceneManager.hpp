//
//  SceneManager.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/20.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef SceneManager_hpp
#define SceneManager_hpp

#include "GlobalHeader.h"
#include "Singleton.h"

#include "SceneBase.hpp"

#include <vector>

NS_ENGINE

class SceneManager : public Util::Singleton<SceneManager> {
  friend class Singleton<SceneManager>;
  
  std::vector<SceneBase*> scenes;
  SceneBase* currentScene;
  
public:
  ~SceneManager();
  void initialize();
  void addScene(SceneBase* scene);
  SceneBase* getScene(int index) const;
  void removeScene(int index);
  void switchSceneTo(int index);
  void switchSceneTo(SceneBase* scene);
  
  void updateScene(GLfloat deltaTime) const;
  
private:
  SceneManager();
};

NS_END

#endif /* SceneManager_hpp */
