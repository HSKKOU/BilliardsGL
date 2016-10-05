#version 410 core
uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

//uniform vec4 color;
layout(location=1) in vec4 color;

in vec4 pv;
out vec4 fragmentColor;

void main() {
  gl_Position = projection * view * model * pv;

  fragmentColor = color;
}
