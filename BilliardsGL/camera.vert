#version 410 core
uniform vec2 size;
uniform float scale;
uniform mat4 MVP;
in vec4 pv;
void main() {
  gl_Position = MVP * pv;
}