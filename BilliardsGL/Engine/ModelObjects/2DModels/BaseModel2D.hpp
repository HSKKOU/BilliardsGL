//
//  BaseModel2D.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/23.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef BaseModel2D_hpp
#define BaseModel2D_hpp

#include "GlobalHeader.h"
#include "Base2D.h"

#include "BaseModel.hpp"

NS_ENGINE_MODEL

class BaseModel2D : public Base2D, public BaseModel {
  
public:
  BaseModel2D();
  BaseModel2D(const Point2D _pos);
  virtual ~BaseModel2D();
  virtual void loadShaderProgram(const char* vs = "./Shaders/Engine/Default.vert", const char* fs = "./Shaders/Engine/Default.frag");
  
protected:
  virtual const GLuint createModel(const GLfloat (*vertices)[2+2], const GLuint vCnt, const int pCnt, const int uvCnt);
  
private:
  GLuint setVertexBuffer(const GLfloat (*vertices)[2+2], const int vSize) const;

};

NS_END2

#endif /* BaseModel2D_hpp */
