//
//  TextureLoader.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/13.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "TextureLoader.hpp"

TextureLoader::TextureLoader()
: textureDict()
{ /* do nothing */ }

void TextureLoader::initialize() {
  glEnable(GL_TEXTURE);
  
  std::map<Tex, std::string> imageNames = {
    { Tex::Stone , "BrownStony" },
    { Tex::Color4, "Color4"     },
    { Tex::Ball01, "Ball01"     },
    { Tex::Ball09, "Ball09"     }
  };
  
  for (int i=0; i<static_cast<int>(Tex::Num); i++) {
    Tex tex = static_cast<Tex>(i);
    std::string imagePath = "./Resources/Textures/" + imageNames[tex] + ".bmp";
    GLuint tId = loadTexture(imagePath.c_str());
    textureDict[tex] = tId;
//    std::cout << "texture load " << tId << " : " << imagePath << std::endl;
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



GLuint TextureLoader::getTextureId(const Tex tex) const { return textureDict.at(tex); }
