//
//  Window.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/15.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef Window_hpp
#define Window_hpp

#include "GlobalHeader.h"

NS_ENGINE

class Window {
  GLFWwindow *const window;
  GLfloat size[2];
  GLfloat scale;
  
public:
  Window(int width = 640, int height = 640, const char *title = "BilliardsGL");
  virtual ~Window();
  
  int shouldClose() const;
  void swapBuffers();
  const GLfloat *getSize() const;
  const GLfloat getScale() const;
  
  void resetWindow();
  
  void getFrameSize(int *width, int *height);
};

NS_END

#endif /* Window_hpp */
