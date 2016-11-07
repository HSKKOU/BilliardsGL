//
//  TextureLoader.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/13.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef TextureLoader_hpp
#define TextureLoader_hpp

#include "GlobalHeader.h"
#include <SOIL/SOIL.h>

#include "Singleton.h"

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

class TextureLoader : public Singleton<TextureLoader> {
  friend class Singleton<TextureLoader>;
  
  std::map<Tex, GLuint> textureDict;
  
public:
  void initialize();
  GLuint loadTexture(const char* imagePath);
  GLuint getTextureId(const Tex tex) const;
  
private:
  TextureLoader();
};



class TexUtil {
public:
  static int toInt(Tex t);
  static Tex toTex(int i);
};

NS_END2

#endif /* TextureLoader_hpp */
