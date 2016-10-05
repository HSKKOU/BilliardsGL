#version 410 core
in vec4 fragmentColor;
out vec4 fc;
vec3 frcl;
void main() {
//  fc = vec4(1.0, 0.0, 0.0, 1.0);

  fc = fragmentColor;
  
//  if (fragmentColor.x != fragmentColor.y || fragmentColor.x != 0.0) {
//    frcl = vec3(0.0);
//  } else {
//    frcl = vec3(0.0, 1.0, 0.0);
//  }
//
//  fc = vec4(frcl.x, frcl.y, frcl.z, 1.0);
}
