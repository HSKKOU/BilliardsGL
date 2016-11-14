//
//  UIManager.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/13.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef UIManager_hpp
#define UIManager_hpp

#include <vector>

#include "Singleton.h"
#include "UI.h"

US_NS_ENGINE_UTIL
US_NS_ENGINE_UI

NS_ENGINE

class UIManager : public Singleton<UIManager> {
  friend class Singleton<UIManager>;
  
  std::vector<UIButton*> buttonList;
  
public:
  ~UIManager();
  void initialize();
  
  void registerButton(UIButton* button);
  
  void recieveEventPressed(Point2D p);
  void recieveEventReleased(Point2D p);
  
  void clearButtonList();
  
private:
  UIManager();
};

NS_END

#endif /* UIManager_hpp */
