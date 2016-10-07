//
//  ObjectFactory.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/07.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef ObjectFactory_hpp
#define ObjectFactory_hpp

#include "GlobalHeader.h"

#include "Models.h"

class ObjectFactory {
  
public:
  static BaseObject3D* instantiateObject(const ObjectType type);
};

#endif /* ObjectFactory_hpp */
