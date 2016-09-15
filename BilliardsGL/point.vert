#version 150 core
uniform vec2 size;
uniform float scale;
in vec4 pv;
void main() {
  gl_Position = pv * vec4(2.0 * scale / size, 1.0, 1.0);
}