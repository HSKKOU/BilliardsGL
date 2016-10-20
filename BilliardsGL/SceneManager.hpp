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

class SceneManager : public Singleton<SceneManager> {
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
  
  void startScene() const;
  void updateScene() const;
  
private:
  SceneManager();
};

#endif /* SceneManager_hpp */
