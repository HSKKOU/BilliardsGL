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
#include "Constants.h"

#include "InputManager.hpp"

NS_ENGINE

class Window {
  GLFWwindow *const window;
  InputManager* inputManagerDelegate;
  
public:
  Window(int width = Const::WINDOW_WIDTH, int height = Const::WINDOW_WIDTH, const char *title = Const::WINDOW_TITLE);
  ~Window();
  
  void setInputManagerDelegate(InputManager* delegate);
  
  int shouldClose() const;
  void swapBuffers();
  
  void resetWindow();
  
  void getFrameSize(int *width, int *height);
  
private:
  void sendMouseEvent();
};

NS_END

#endif /* Window_hpp */
