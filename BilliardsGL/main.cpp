//
//  main.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/15.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include <cstdlib>

#include "GlobalHeader.h"
#include "GameManager.hpp"

int main(int argc, const char * argv[]) {

  // initialize GLFW
  if (glfwInit() == GL_FALSE) {
    std::cerr << "Can't initialize GLFW" << std::endl;
    return 1;
  }
  
  // register operation terminated program
  atexit(glfwTerminate);
  
  // select OpenGL Version 4.1 Core Profile
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  
  
  GameManager &gameManager = GameManager::instance();
  gameManager.initialize();  
  gameManager.startMainLoop();  
}
