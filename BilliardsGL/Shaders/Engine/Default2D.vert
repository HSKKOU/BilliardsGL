#version 410 core

layout(location=1) in vec4 objectColor;

in vec4 pv;

void main() {
  gl_Position = pv;
}
