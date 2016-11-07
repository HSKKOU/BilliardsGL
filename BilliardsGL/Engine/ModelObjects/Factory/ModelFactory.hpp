//
//  ModelFactory.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/07.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef ModelFactory_hpp
#define ModelFactory_hpp

#include "GlobalHeader.h"

#include "Models.h"

NS_ENGINE_MODEL

class ModelFactory {
  
public:
  static BaseModel3D* instantiateSimpleModel(const ModelType type);
  static Sphere* createSphereModel(const GLfloat radius);
  static Cube* createCubeModel(const Vector3D size);
};

NS_END2

#endif /* ModelFactory_hpp */
