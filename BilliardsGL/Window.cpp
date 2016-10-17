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
}

Window::~Window() { glfwDestroyWindow(window); }

int Window::shouldClose() const { return glfwWindowShouldClose(window); }

void Window::swapBuffers() {
  glfwSwapBuffers(window);
  glfwPollEvents();
  
  if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) != GLFW_RELEASE) {
    double x, y;
    glfwGetCursorPos(window, &x, &y);
  }
  
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_CULL_FACE);
}

void Window::readyWindow() { /* do nothing */ }
void Window::resetBuffer() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
}

const GLfloat* Window::getSize() const { return size; }
const GLfloat Window::getScale() const { return scale; }

void Window::getFrameSize(int *width, int *height) { glfwGetFramebufferSize(window, width, height); }


