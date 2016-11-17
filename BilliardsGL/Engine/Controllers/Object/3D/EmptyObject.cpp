//
//  EmptyObject.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/23.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "EmptyObject.hpp"

NS_ENGINE

EmptyObject::EmptyObject(Transform t)
: Engine::BaseObject3D(t, Surface())
{ /* do nothing */ }
EmptyObject::~EmptyObject() { /* do nothing */ }

NS_END
