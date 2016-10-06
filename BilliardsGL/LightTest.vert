#version 410 core
uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

in vec3 pv;
in vec4 color;

out vec4 objectColor;

void main() {
  gl_Position = projection * view * model * vec4(pv, 1.0f);
  
  objectColor = color;
}
