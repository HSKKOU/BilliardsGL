//
//  UIBase.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/13.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef UIBase_hpp
#define UIBase_hpp

#include "SquareObject2D.hpp"

#include "Constants.h"

NS_ENGINE_UI

typedef uint64_t UI_ALIGNMENT_MASK;
struct UI_ALIGNMENT {
  static const UI_ALIGNMENT_MASK None    = 0b0000;
  static const UI_ALIGNMENT_MASK Top     = 0b0001;
  static const UI_ALIGNMENT_MASK Right   = 0b0010;
  static const UI_ALIGNMENT_MASK Left    = 0b0100;
  static const UI_ALIGNMENT_MASK Bottom  = 0b1000;
};

class UIBase : public SquareObject2D {
protected:
  Point2D uiPosition;
  Vector2D uiSize;
  
public:
  UIBase(Point2D p, Vector2D s, UI_ALIGNMENT_MASK alignmentMask);
  virtual ~UIBase();
  
  virtual void awake();
};

NS_END2

#endif /* UIBase_hpp */
