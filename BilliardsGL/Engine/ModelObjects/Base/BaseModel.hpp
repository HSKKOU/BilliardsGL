//
//  BaseModel.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/11/11.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef BaseModel_hpp
#define BaseModel_hpp

#include "Matrix.h"

#include "ShaderLoader.hpp"

#include "Textures.h"
#include "TextureLoader.hpp"

US_NS_ENGINE_UTIL

NS_ENGINE_MODEL

struct AttribLoc {
  GLuint position = 0;
  GLuint uv = 1;
  GLuint normal = 3;
  int num = 3;
  AttribLoc(){ /* do nothing */ }
  AttribLoc(GLuint _p, GLuint _uv, GLuint _n, int _num) :position(_p), uv(_uv), normal(_n), num(_num) { /* do nothing */ }
};

struct Shaders {
  const char* vSrc;
  const char* fSrc;
};

struct Vertices {
  GLuint vao;
  GLsizei count;
};

typedef GLuint TextureID;


class BaseModel {
protected:
  AttribLoc attribLoc;
  Vertices vertices;
  TextureID textureId;
  Color objectColor;
  
  GLuint vertexBuffer;
  
  GLuint shaderProgram;
  Shaders shaders;
    
public:
  BaseModel();
  virtual ~BaseModel();
  
  // accessor
  Color getObjectColor() const;
  void setObjectColor(const Color c);

  virtual void setTexture(ETex tex);

  virtual void loadShaderProgram(const char* vs = "./Shaders/Engine/Default.vert", const char* fs = "./Shaders/Engine/Default.frag");
  
  virtual void draw();
  virtual void drawReady();
  virtual void sendParams2Shd() = 0;
  virtual void drawRun(int mode = GL_TRIANGLES);

protected:
  virtual void setShaderLoc() = 0;
  virtual void sendColor2Shd() const = 0;
  void sendTexture2Shd() const;

  GLuint readyVAO() const;
  void setPositionBuffer(const int vCnt, const int offset, const int dim) const;
  void setNormalBuffer(const int vCnt, const int offset) const;
  void setUVBuffer(const int vCnt, const int offset) const;
  void setEachVertexBuffer(const GLuint loc, const int size, const int vCnt, const int offset) const;
  void releaseBuffer() const;
};

NS_END2

#endif /* BaseModel_hpp */
