//
//  Math.h
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/12/12.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef Math_h
#define Math_h

#include "GlobalHeader.h"

NS_ENGINE

class Math {
public:
  static GLfloat sign(GLfloat x) { return (x>0) - (x<0); }
};

NS_END

#endif /* Math_h */
