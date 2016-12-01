//
//  Constants.h
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/11.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef Constants_h
#define Constants_h

#include "GlobalHeader.h"

NS_ENGINE_CONST

/* Window */
const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 640;
const char WINDOW_TITLE[] = "BilliardsGL";
/* end Window */




/* Physics */

// rate of decreacing velocity
const GLfloat DEC_VELOCITY_RATE = 0.99f;
// threshold of minimun velocity length
const GLfloat VELOCITY_EPS = 0.01f;
// Gravity Acceleration
const GLfloat GRAVITY_ACCEL = 9.8f;

/* end Physics */

NS_END2

#endif /* Constants_h */
