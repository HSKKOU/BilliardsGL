#version 410 core
uniform vec2 size;
uniform float scale;
uniform vec2 position;
in vec4 pv;
void main() {
  gl_Position = pv * vec4(2.0 * scale / size, 1.0, 1.0);
}