#version 410 core
uniform vec2 position;

layout(location=1) in vec4 objectColor;

in vec4 pv;

void main() {
  gl_Position = pv + vec4(position, 0.0f, 0.0f);
}
