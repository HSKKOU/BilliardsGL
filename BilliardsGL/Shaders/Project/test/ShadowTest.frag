#version 410 core

out vec4 fc;
layout(location = 0) out float fragmentdepth;

void main() {
  fragmentdepth = gl_FragCoord.z;
  fc = vec4(1.0f);
}
