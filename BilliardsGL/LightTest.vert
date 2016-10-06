#version 410 core
uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

in vec4 pv;

void main() {
  gl_Position = projection * view * model * pv;
}
