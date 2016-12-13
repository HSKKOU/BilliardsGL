#version 410 core
uniform vec4 objectColor;
uniform sampler2D tex;

in vec2 TexCoord;

out vec4 fc;

void main() {
//  fc = vec4(0.8823f, 0.0f, 0.698f, 1.0f);
  fc = texture(tex, TexCoord) * objectColor;
}
