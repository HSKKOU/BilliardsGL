#version 410 core

uniform vec4 objectColor;

uniform vec3 lightPos;
uniform vec4 lightColor;

in vec3 objectNormal;
in vec3 fragPos;

out vec4 fc;

void main() {
  float ambientStrength = 0.3f;
  vec3 oColor = vec3(objectColor);
  vec3 ambient = ambientStrength * oColor;
  
  vec3 norm = normalize(objectNormal);
  vec3 lightDir = normalize(lightPos - fragPos);
  
  float diff = max(dot(norm, lightDir), 0.0f);
  vec3 diffuse = diff * vec3(lightColor);
  
  vec3 rv = (ambient+ diffuse) * oColor;
  
  fc = vec4(rv, objectColor.w);
}
