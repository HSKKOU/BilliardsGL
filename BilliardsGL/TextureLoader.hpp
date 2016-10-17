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

enum class Tex : int {
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

#endif /* TextureLoader_hpp */
