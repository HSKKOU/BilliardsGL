//
//  TextureLoader.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/13.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef TextureLoader_hpp
#define TextureLoader_hpp

#include <SOIL/SOIL.h>

#include <string>
#include <map>

#include "Singleton.h"
#include "Textures.h"

NS_ENGINE_UTIL

class TextureLoader : public Singleton<TextureLoader> {
  friend class Singleton<TextureLoader>;
  
  std::map<ETex, GLuint> textureDict;
  
public:
  ~TextureLoader();
  GLuint loadTexture(const char* imagePath);
  GLuint getTextureId(const ETex tex) const;
  
private:
  TextureLoader();
};



class TexUtil {
public:
  static int toInt(ETex t);
  static ETex toTex(int i);
};

NS_END2

#endif /* TextureLoader_hpp */
