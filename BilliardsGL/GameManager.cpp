//
//  GameManager.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/15.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "GameManager.hpp"


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



GameManager::GameManager() { /* do nothing */ }

void GameManager::initialize() {
  // set background color
  glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
}

void GameManager::startMainLoop() {
  
  FPSCounter &fps = FPSCounter::instance();
  fps.initialize(glfwGetTime());
  
  square = new Square(-0.5f, -0.5f, 1.0f, 1.0f);
  
  program = loadProgram("point.vert", "pv", "point.frag", "fc");
  sizeLoc = glGetUniformLocation(program, "size");
  scaleLoc = glGetUniformLocation(program, "scale");
  positionLoc = glGetUniformLocation(program, "position");

  while (window.shouldClose() == GL_FALSE) {
    fps.update(glfwGetTime());
    
    mainLoop();
  }
}


void GameManager::mainLoop() {
//  std::cout << "main loop" << std::endl;

  glClear(GL_COLOR_BUFFER_BIT);

  glUseProgram(program);

  glUniform2fv(sizeLoc, 1, window.getSize());
  glUniform1f(scaleLoc, window.getScale());
  glUniform2fv(positionLoc, 1, window.getPosition());
  
  square->draw();

  window.swapBuffers();
}