//
//  UIButton.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/13.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef UIButton_hpp
#define UIButton_hpp

#include "UIPanel.hpp"

NS_ENGINE_UI

class IButtonHandler {
public:
  virtual ~IButtonHandler() {}
  virtual void onButtonDown() = 0;
  virtual void onButtonDownRepeat() = 0;
  virtual void onButtonUp() = 0;
};

class UIButton : public UIPanel {
protected:
  bool isPressedFlag;
  IButtonHandler* handler;
  
public:
  UIButton(Point2D p, Vector2D s, UI_ALIGNMENT_MASK mask, Color c);
  virtual ~UIButton();
  
  virtual void setHandler(IButtonHandler* hdl);

  virtual void awake();
  
  virtual bool isInRange(Point2D p) const;
  virtual bool isPressed() const;

  virtual void press();
  virtual void pressRepeat();
  virtual void release();
};

NS_END2

#endif /* UIButton_hpp */
