//
//  UIBase.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/13.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "UIBase.hpp"

NS_ENGINE_UI

UIBase::UIBase(Point2D p, Vector2D s, UI_ALIGNMENT_MASK alignmentMask)
: Engine::SquareObject2D( p, s.divide(Const::WINDOW_WIDTH, Const::WINDOW_HEIGHT) )
, uiPosition(p)
, uiSize(s)
{
  Point2D alignedPos = p;
  if (alignmentMask == UI_ALIGNMENT::None) {
    /* do nothing */
  } else {
    if (
        ((alignmentMask & UI_ALIGNMENT::Top) && (alignmentMask & UI_ALIGNMENT::Bottom))
        ||
        ((alignmentMask & UI_ALIGNMENT::Left) && (alignmentMask & UI_ALIGNMENT::Right))
       )
    {
      /* do nothing */
    } else {
      if (alignmentMask & UI_ALIGNMENT::Top)    { alignedPos.y = Const::WINDOW_HEIGHT - alignedPos.y; }
      if (alignmentMask & UI_ALIGNMENT::Bottom) { alignedPos.y = alignedPos.y - Const::WINDOW_HEIGHT; }
      if (alignmentMask & UI_ALIGNMENT::Left)   { alignedPos.x = alignedPos.x - Const::WINDOW_WIDTH ; }
      if (alignmentMask & UI_ALIGNMENT::Right)  { alignedPos.x = Const::WINDOW_WIDTH - alignedPos.x ; }
    }
  }

  position = alignedPos.divide(Const::WINDOW_WIDTH, Const::WINDOW_HEIGHT);
}

UIBase::~UIBase() { /* do nothing */ }


void UIBase::awake() {
  createSquareModel(ETex::None, Color::one());
}

NS_END2
