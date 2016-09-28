#version 410 core
uniform vec2 size;
uniform float scale;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

layout(location=1) in vec3 vertexColor;
in vec4 pv;
out vec3 fragColor;

void main() {
  gl_Position = projection * view * model * pv;

//  fragColor = vertexColor;

//  gl_Position = pv;
}