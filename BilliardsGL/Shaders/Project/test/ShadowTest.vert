#version 410 core
uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

uniform mat4 depthProjection;
uniform mat4 depthView;

in vec3 pv;

void main() {
//  gl_Position = projection * view * model * vec4(pv, 1.0f);
  gl_Position = depthProjection * depthView * model * vec4(pv, 1.0f);
}
