//
//  TextureLoader.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/13.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "TextureLoader.hpp"

NS_ENGINE_UTIL

TextureLoader::TextureLoader()
: textureDict()
{ /* do nothing */ }

void TextureLoader::initialize() {
  glEnable(GL_TEXTURE);
  
  for (int i=0; i<static_cast<int>(ETex::Num); i++) {
    ETex tex = static_cast<ETex>(i);
    std::string imagePath = Textures::getTexturePath(tex);
    GLuint tId = loadTexture(imagePath.c_str());
    textureDict[tex] = tId;
  }
}

GLuint TextureLoader::loadTexture(const char* imagePath) {
  GLuint textureId;
  glGenTextures(1, &textureId);
  glBindTexture(GL_TEXTURE_2D, textureId);
  
  int width, height;
  unsigned char* image = SOIL_load_image(imagePath, &width, &height, 0, SOIL_LOAD_RGB);
//  std::cout << "[SOIL] image size : width(" << width << "), height(" << height << ")" << std::endl;
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
  glGenerateMipmap(GL_TEXTURE_2D);
  SOIL_free_image_data(image);
  glBindTexture(GL_TEXTURE_2D, 0);
  
  return textureId;
}



GLuint TextureLoader::getTextureId(const ETex tex) const { return textureDict.at(tex); }






int TexUtil::toInt(ETex t) { return static_cast<int>(t); }
ETex TexUtil::toTex(int i) { return static_cast<ETex>(i); }

NS_END2
