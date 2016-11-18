//
//  BoardController.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/13.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef BoardController_hpp
#define BoardController_hpp

#include "ObjectBehavior.hpp"
#include "CubeRigidObject3D.hpp"

#include "ObjectManager.hpp"

#include <vector>

US_NS_ENGINE

NS_GAME

class BoardController : public Base3D, public ObjectBehavior {
  std::vector<CubeRigidObject3D*> stageCubeList;
  
public:
  BoardController(Transform t);
  ~BoardController();

  void setupStage();
  
private:
  CubeRigidObject3D* createFloor();
};

NS_END

#endif /* BoardController_hpp */
