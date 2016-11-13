//
//  Window.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/15.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "Window.hpp"

NS_ENGINE

Window::Window(int width, int height, const char *title)
: window(glfwCreateWindow(width, height, title, nullptr, nullptr))
{
  
  if (window == nullptr) {
    std::cerr << "Can't create GLFW window." << std::endl;
    exit(EXIT_FAILURE);
  }
  
  glfwMakeContextCurrent(window);
  
  // initialize GLEW
  glewExperimental = GL_TRUE;
  if (glewInit() != GLEW_OK) {
    std::cerr << "Can't initialize GLEW" << std::endl;
    exit(EXIT_FAILURE);
  }

  glfwSwapInterval(1);
  
  glfwSetWindowUserPointer(window, this);
}

Window::~Window() {
  inputManagerDelegate = nullptr;
  glfwDestroyWindow(window);
}


void Window::setInputManagerDelegate(InputManager* delegate) { inputManagerDelegate = delegate; }

int Window::shouldClose() const { return glfwWindowShouldClose(window); }

void Window::swapBuffers() {
  glfwSwapBuffers(window);
  
  sendMouseEvent();

  glfwPollEvents();

  glDisable(GL_DEPTH_TEST);
  glDisable(GL_CULL_FACE);
}

void Window::sendMouseEvent() {
  // TODO: use only BUTTON_1 for Debug
  double x, y;
  switch (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1)) {
    case GLFW_PRESS:
      glfwGetCursorPos(window, &x, &y);
      inputManagerDelegate->pressedButton(EButton::Button1, Point2D(x,y));
      break;
    case GLFW_RELEASE:
      glfwGetCursorPos(window, &x, &y);
      inputManagerDelegate->releasedButton(EButton::Button1, Point2D(x,y));
      break;

    default:
      break;
  }
}

void Window::resetWindow() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
}

void Window::getFrameSize(int *width, int *height) { glfwGetFramebufferSize(window, width, height); }

NS_END
