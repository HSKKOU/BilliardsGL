//
//  Window.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/15.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "Window.hpp"

Window::Window(int width, int height, const char *title)
: window(glfwCreateWindow(width, height, title, nullptr, nullptr))
, scale(100.0f) {
  if (window == nullptr) {
    std::cerr << "Can't create GLFW window." << std::endl;
    exit(1);
  }
  
  glfwMakeContextCurrent(window);
  
  // initialize GLEW
  glewExperimental = GL_TRUE;
  if (glewInit() != GLEW_OK) {
    std::cerr << "Can't initialize GLEW" << std::endl;
    exit(1);
  }

  glfwSwapInterval(1);
  
  glfwSetWindowUserPointer(window, this);
  
  glfwSetWindowSizeCallback(window, resize);
  
  resize(window, width, height);
}

Window::~Window() {
  glfwDestroyWindow(window);
}

int Window::shouldClose() const {
  return glfwWindowShouldClose(window);
}

void Window::swapBuffers() {
  glfwSwapBuffers(window);
  glfwWaitEvents();
}

const GLfloat* Window::getSize() const { return size; }
const GLfloat Window::getScale() const { return scale; }

void Window::resize(GLFWwindow *const window, int width, int height) {
  glViewport(0, 0, width*2, height*2);
  
  Window *const instance = static_cast<Window *>(glfwGetWindowUserPointer(window));
  if (instance != nullptr) {
    instance->size[0] = static_cast<GLfloat>(width);
    instance->size[1] = static_cast<GLfloat>(height);
  }
}