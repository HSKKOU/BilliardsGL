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

NS_ENGINE_MODEL

class ObjectFactory {
  
public:
  static BaseObject3D* instantiateObject(const ObjectType type);
};

NS_END2

#endif /* ObjectFactory_hpp */
