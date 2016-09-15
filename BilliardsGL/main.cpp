//
//  main.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/15.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include <cstdlib>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main(int argc, const char * argv[]) {

  // initialize GLFW
  if (glfwInit() == GL_FALSE) {
    std::cerr << "Can't initialize GLFW" << std::endl;
    return 1;
  }
  
  // register operation terminated program
  atexit(glfwTerminate);
  
  // select OpenGL Version 3.2 Core Profile
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  
  // create window
  GLFWwindow *const window = glfwCreateWindow(640, 480, "Hello!", nullptr, nullptr);
  if (window == nullptr) {
    std::cerr << "Can't create GLFW window." << std::endl;
    return 1;
  }
  
  glfwMakeContextCurrent(window);
  
  // initialize GLEW
  glewExperimental = GL_TRUE;
  if (glewInit() != GLEW_OK) {
    std::cerr << "Can't initialize GLEW" << std::endl;
    return 1;
  }
  
  // wait vertical sync
  glfwSwapInterval(1);
  
  // set background color
  glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
  
  // drawing loop
  while (glfwWindowShouldClose(window) == GL_FALSE) {
    glClear(GL_COLOR_BUFFER_BIT);
    
    //
    // drawing
    //
    
    glfwSwapBuffers(window);
    glfwWaitEvents();
  }
}
