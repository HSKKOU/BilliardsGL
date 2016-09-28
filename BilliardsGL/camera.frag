#version 410 core
in vec3 fragColor;
out vec4 fc;
void main() {
  fc = vec4(1.0, 0.0, 0.0, 1.0);
//  fc = vec4(fragColor, 1.0);
}