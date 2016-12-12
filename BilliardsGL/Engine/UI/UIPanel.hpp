//
//  UIPanel.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/13.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef UIPanel_hpp
#define UIPanel_hpp

#include "UIBase.hpp"

NS_ENGINE_UI

class UIPanel : public UIBase {
  Color panelColor;
  
public:
  UIPanel(Point2D p, Vector2D s, ETex tex, UI_ALIGNMENT_MASK mask, Color c);
  virtual ~UIPanel();
  
  virtual void awake();
};

NS_END2

#endif /* UIPanel_hpp */
