#version 410 core

in vec3 fragPos;

out vec4 fc;

void main() {
  fc = vec4(fragPos, 1.0f);
}
