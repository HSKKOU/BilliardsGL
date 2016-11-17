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

enum class ETex : int {
  None,
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
  BFloor,
  Num,
};

class Textures {
  
public:
  static std::map<ETex, std::string> getTexturesMap() {
    return {
      { ETex::None  , "Default"    },
      { ETex::Ball00, "White"      },
      { ETex::Ball01, "Ball01"     },
      { ETex::Ball02, "Ball02"     },
      { ETex::Ball03, "Ball03"     },
      { ETex::Ball04, "Ball04"     },
      { ETex::Ball05, "Ball05"     },
      { ETex::Ball06, "Ball06"     },
      { ETex::Ball07, "Ball07"     },
      { ETex::Ball08, "Ball08"     },
      { ETex::Ball09, "Ball09"     },
      { ETex::Ball10, "Ball10"     },
      { ETex::Ball11, "Ball11"     },
      { ETex::Ball12, "Ball12"     },
      { ETex::Ball13, "Ball13"     },
      { ETex::Ball14, "Ball14"     },
      { ETex::Ball15, "Ball15"     },
      { ETex::Stone , "Stone"      },
      { ETex::BFloor, "White"      },
    };
  }
  
  static std::string getTexturePath(ETex tex) {
    return "./Resources/Textures/" + getTexturesMap()[tex] + ".png";
  }
  
  static std::string getTexturePath(int index) {
    return "./Resources/Textures/" + getTexturesMap()[static_cast<ETex>(index)] + ".png";
  }
};

NS_END2


#endif /* Textures_h */
