#version 410 core

in vec4 objectColor;

out vec4 fc;

void main() {
  float ambientStrength = 0.9f;
  vec4 ambient = ambientStrength * objectColor;
  
  fc = ambient;
}
