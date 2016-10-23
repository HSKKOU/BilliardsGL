//
//  EmptyObject.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/23.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef EmptyObject_hpp
#define EmptyObject_hpp

#include "BaseObject3D.hpp"

NS_ENGINE

class EmptyObject : public BaseObject3D {
  
public:
  EmptyObject(Transform t);
  virtual ~EmptyObject();
  
};

NS_END

#endif /* EmptyObject_hpp */
