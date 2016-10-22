//
//  BaseObject3D.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/22.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef BaseObject3D_hpp
#define BaseObject3D_hpp

#include "GlobalHeader.h"
#include <vector>

#include "Base3D.h"
#include "BaseModel3D.hpp"

US_NS_ENGINE_MODEL

NS_ENGINE

class BaseObject3D : public Base3D {
  std::vector<BaseModel3D*> modelList;
  
public:
  BaseObject3D();
  BaseObject3D(Transform t);
  virtual ~BaseObject3D();
  
  void addModel(BaseModel3D* model);
  BaseModel3D* getModel(int index) const;
  void removeModel(int index);
  
  void virtual awake();
  void virtual start();
  void virtual update();
  void virtual lateUpdate();
};

NS_END

#endif /* BaseObject3D_hpp */
