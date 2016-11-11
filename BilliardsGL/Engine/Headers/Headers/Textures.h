//
//  Textures.h
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/11.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef Textures_h
#define Textures_h

#include "GlobalHeader.h"
#include <string>
#include <map>

NS_ENGINE_UTIL

enum class Tex : int {
  Ball00,
  Ball01,
  Ball02,
  Ball03,
  Ball04,
  Ball05,
  Ball06,
  Ball07,
  Ball08,
  Ball09,
  Ball10,
  Ball11,
  Ball12,
  Ball13,
  Ball14,
  Ball15,
  Stone,
  Num,
};

class Textures {
  
public:
  static std::map<Tex, std::string> getTexturesMap() {
    return {
      { Tex::Ball00, "Ball00"     },
      { Tex::Ball01, "Ball01"     },
      { Tex::Ball02, "Ball02"     },
      { Tex::Ball03, "Ball03"     },
      { Tex::Ball04, "Ball04"     },
      { Tex::Ball05, "Ball05"     },
      { Tex::Ball06, "Ball06"     },
      { Tex::Ball07, "Ball07"     },
      { Tex::Ball08, "Ball08"     },
      { Tex::Ball09, "Ball09"     },
      { Tex::Ball10, "Ball10"     },
      { Tex::Ball11, "Ball11"     },
      { Tex::Ball12, "Ball12"     },
      { Tex::Ball13, "Ball13"     },
      { Tex::Ball14, "Ball14"     },
      { Tex::Ball15, "Ball15"     },
      { Tex::Stone , "BrownStony" },
    };
  }
  
  static std::string getTexturePath(Tex tex) {
    return "./Resources/Textures/" + getTexturesMap()[tex] + ".png";
  }
  
  static std::string getTexturePath(int index) {
    return "./Resources/Textures/" + getTexturesMap()[static_cast<Tex>(index)] + ".png";
  }
};

NS_END2


#endif /* Textures_h */
