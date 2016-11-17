#version 410 core

uniform vec4 objectColor;

uniform vec3 lightPos;
uniform vec3 lightDir;
uniform vec4 lightColor;

uniform vec3 cameraPos;

uniform sampler2D tex;

in vec3 objectNormal;
in vec3 fragPos;

in vec2 TexCoord;

out vec4 fc;

void main() {
  vec3 normal = normalize(objectNormal);
  
  // directional or spot light
  vec3 lDir = lightDir;
  if (lDir == vec3(0.0f)) {
    lDir = normalize(lightPos - fragPos);
  }

  // ambient
  float ambientStrength = 0.7f;
  vec3 oColor = vec3(objectColor);
//  vec3 oColor = vec3(1.0f, 0.0f, 0.0f);
  vec3 ambient = ambientStrength * oColor;
  
  // diffuse
  float diff = max(dot(normal, lDir), 0.0f);
  vec3 diffuse = diff * vec3(lightColor);
  
  // specular
  float specularStrength = 0.5f;
  vec3 viewDir = normalize(cameraPos - fragPos);
  vec3 reflectDir = reflect(-lDir, normal);
  float spec = pow(max(dot(viewDir, reflectDir), 0.0f), 32);
  vec3 specular = specularStrength * spec * vec3(lightColor);
  
  
  vec3 rv = (ambient + diffuse + specular) * oColor;
  
  fc = vec4(rv, objectColor.w);
  
//  fc = texture(tex, TexCoord);
  
  fc = texture(tex, TexCoord) * vec4(rv, objectColor.w);
}
