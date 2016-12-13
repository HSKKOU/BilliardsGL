#version 410 core
uniform vec2 position;

in vec4 pv;
in vec2 uv;

out vec2 TexCoord;

void main() {
  gl_Position = pv + vec4(position, 0.0f, 0.0f);
  TexCoord = uv;
}
