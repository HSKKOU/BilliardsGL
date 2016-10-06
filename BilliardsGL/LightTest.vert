#version 410 core
uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

in vec3 pv;
in vec3 normal;

out vec3 objectNormal;
out vec3 fragPos;

void main() {
  gl_Position = projection * view * model * vec4(pv, 1.0f);
  fragPos = vec3(model * vec4(pv, 1.0f));

  objectNormal = mat3(transpose(inverse(model))) * normal;
}
