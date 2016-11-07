#version 410 core
uniform vec2 size;
uniform float scale;
in vec4 pv;
void main() {
  gl_Position = pv * vec4(1.0f, 1.0f, 1.0f, 1.0f);
}
