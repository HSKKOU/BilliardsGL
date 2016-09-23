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

class Window {
  GLFWwindow *const window;
  GLfloat size[2];
  GLfloat scale;
  GLfloat position[2];
  
public:
  Window(int width = 640, int height = 480, const char *title = "Hello!");
  virtual ~Window();
  
  int shouldClose() const;
  void swapBuffers();
  const GLfloat *getSize() const;
  const GLfloat getScale() const;
  const GLfloat *getPosition() const;
  static void resize(GLFWwindow *const window, int width, int height);
  static void wheel(GLFWwindow *const window, double x, double y);
};

#endif /* Window_hpp */
