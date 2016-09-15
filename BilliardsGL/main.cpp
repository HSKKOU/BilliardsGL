//
//  main.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/15.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


// print gl error log
GLboolean printShaderInfoLog (GLuint shader, const char *str) {
  GLint status;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
  if (status == GL_FALSE) { std::cerr << "Compile Error in " << str << std::endl; }
  
  GLsizei bufSize;
  glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &bufSize);
  
  if (bufSize > 1) {
    std::vector<GLchar> infoLog(bufSize);
    GLsizei length;
    glGetShaderInfoLog(shader, bufSize, &length, &infoLog[0]);
    std::cerr << &infoLog[0] << std::endl;
  }
  
  return static_cast<GLboolean>(status);
}
GLboolean printProgramInfoLog (GLuint program) {
  GLint status;
  glGetProgramiv(program, GL_LINK_STATUS, &status);
  if (status == GL_FALSE) { std::cerr << "Link Error." << std::endl; }
  
  GLsizei bufSize;
  glGetProgramiv(program, GL_INFO_LOG_LENGTH, &bufSize);
  
  if (bufSize > 1) {
    std::vector<GLchar> infoLog(bufSize);
    GLsizei length;
    glGetProgramInfoLog(program, bufSize, &length, &infoLog[0]);
    std::cerr << &infoLog[0] << std::endl;
  }
  
  return static_cast<GLboolean>(status);
}

// create shader program
GLuint createProgram (const char *vsrc, const char *pv, const char *fsrc, const char *fc) {
  const GLuint program = glCreateProgram();
  
  if (vsrc != nullptr) {
    const GLuint vobj = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vobj, 1, &vsrc, nullptr);
    glCompileShader(vobj);
    
    if (printShaderInfoLog(vobj, "vertex shader")) { glAttachShader(program, vobj); }
    glDeleteShader(vobj);
  }
  
  if (fsrc != nullptr) {
    const GLuint fobj = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fobj, 1, &fsrc, nullptr);
    glCompileShader(fobj);
    
    if (printShaderInfoLog(fobj, "fragment shader")) { glAttachShader(program, fobj); }
    glDeleteShader(fobj);
  }
  
  glBindAttribLocation(program, 0, pv);
  glBindFragDataLocation(program, 0, fc);
  glLinkProgram(program);
  
  if (printProgramInfoLog(program)) { return program; }
  
  glDeleteProgram(program);
  return 0;
}

GLchar *readShaderSource (const char *name) {
  if (name == nullptr) return nullptr;
  std::ifstream file(name, std::ios::binary);
  if (file.fail()) {
    std::cerr << "Error: Can't open source file: " << name << std::endl;
    return nullptr;
  }

  file.seekg(0L, std::ios::end);
  const GLsizei length(static_cast<GLsizei>(file.tellg()));
  GLchar *buffer(new(std::nothrow) GLchar[length + 1]);
  if (buffer == nullptr) {
    std::cerr << "Error: Too large file: " << name << std::endl;
    file.close();
    return nullptr;
  }

  file.seekg(0L, std::ios::beg);
  file.read(buffer, length);
  buffer[length] = '\0';
  if (file.bad()) {
    std::cerr << "Error: Could not read souce file: " << name << std::endl;
    delete[] buffer;
    buffer = nullptr;
  }
  file.close();
  
  return buffer;
}

GLuint loadProgram(const char *vert, const char *pv, const char *frag, const char *fc) {
  const GLchar *vsrc = readShaderSource(vert);
  const GLchar *fsrc = readShaderSource(frag);
  const GLuint program = createProgram(vsrc, pv, fsrc, fc);
  delete vsrc;
  delete fsrc;
  return program;
}




// create object
GLuint createObject (GLuint vertices, const GLfloat (*position)[2]) {
  GLuint vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);
  
  GLuint vbo;
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*2*vertices, position, GL_STATIC_DRAW);
  
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(0);

  glBindVertexArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  
  return vao;
}

struct Object {
  GLuint vao;
  GLsizei count;
};

Object createRectangle () {
  static const GLfloat position[][2] =
  {
    { -0.5f, -0.5f },
    {  0.5f, -0.5f },
    {  0.5f,  0.5f },
    { -0.5f,  0.5f }
  };
  
  static const int vertices = sizeof(position) / sizeof(position[0]);
  
  Object object;
  object.vao = createObject(vertices, position);
  object.count = vertices;
  
  return object;
}







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
  
  
  const GLuint program = loadProgram("point.vert", "pv", "point.frag", "fc");
  
  const Object object = createRectangle();
  
  // drawing loop
  while (glfwWindowShouldClose(window) == GL_FALSE) {
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(program);
    
    glBindVertexArray(object.vao);
    glDrawArrays(GL_LINE_LOOP, 0, object.count);
    
    glfwSwapBuffers(window);
    glfwWaitEvents();
  }
}
