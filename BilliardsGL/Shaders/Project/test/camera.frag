#version 410 core
in vec4 fragmentColor;
out vec4 fc;
vec3 frcl;
void main() {
//  fc = vec4(1.0f, 0.0f, 0.0f, 1.0f);

  fc = fragmentColor;
  
//  if (fragmentColor.x != fragmentColor.y || fragmentColor.x != 0.0f) {
//    frcl = vec3(0.0f);
//  } else {
//    frcl = vec3(0.0f, 1.0f, 0.0f);
//  }
//
//  fc = vec4(frcl.x, frcl.y, frcl.z, 1.0f);
}
