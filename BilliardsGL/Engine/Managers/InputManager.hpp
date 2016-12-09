//
//  InputManager.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/13.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef InputManager_hpp
#define InputManager_hpp

#include "Singleton.h"
#include "Matrix.h"

#include "Constants.h"

#include "UIManager.hpp"

US_NS_ENGINE_UTIL

NS_ENGINE

enum class EButton {
  None,
  Button1,   // left click
  Num,
};

class InputManager : public Singleton<InputManager> {
  friend class Singleton<InputManager>;
  
  UIManager* uiManagerDelegate;
  
public:
  ~InputManager();
  
  void setUIManagerDelegate(UIManager* delegate);
  
  // delegate function by Window
  void pressedButton(EButton btn, Point2D point);
  void releasedButton(EButton btn, Point2D point);
  
private:
  InputManager();
  void calcMousePointCentering(Point2D& point);
  
};

NS_END

#endif /* InputManager_hpp */
