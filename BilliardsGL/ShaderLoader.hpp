//
//  ShaderLoader.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/24.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef ShaderLoader_hpp
#define ShaderLoader_hpp

#include "GlobalHeader.h"
#include "Singleton.h"

#include <vector>
#include <fstream>

class ShaderLoader : public Singleton<ShaderLoader> {
  friend class Singleton<ShaderLoader>;
  
public:
  static GLuint loadShaderProgram(const char *vert, const char *pv, const char *frag, const char *fc);
  
private:
  ShaderLoader();
  static GLboolean printShaderInfoLog (GLuint shader, const char *str);
  static GLboolean printProgramInfoLog (GLuint program);
  static GLuint createProgram (const char *vsrc, const char *pv, const char *fsrc, const char *fc);
  static GLchar *readShaderSource (const char *name);
};

#endif /* ShaderLoader_hpp */
