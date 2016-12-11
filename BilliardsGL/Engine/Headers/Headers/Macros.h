//
//  Macros.h
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/12/11.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef Macros_h
#define Macros_h

#define SAFE_DELETE(x) {\
  delete (x);\
  x = nullptr;\
}

#define SAFE_DELETE_VECTOR(vec, type) {\
  for (type* elem : vec) { SAFE_DELETE(elem); }\
  vec.clear();\
}

#endif /* Macros_h */
