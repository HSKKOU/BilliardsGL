//
//  CameraController.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/26.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef CameraController_hpp
#define CameraController_hpp

#include "GlobalHeader.h"
#include "Base3D.h"

#include "glm/gtc/matrix_transform.hpp"

class CameraController : public Base3D {
  Vector3D direction;
  Vector3D upDir;
  Vector3D rightDir;
  
  GLfloat angle = 0.0;
  GLfloat near = 0.0;
  GLfloat far = 0.0;
  Matrix4D projection;
  
public:
  CameraController(Vector3D _pos, Vector3D _dir, Vector3D _up = Vector3D::up());
  virtual ~CameraController();
  
  glm::mat4 getViewMatrix();
  
  Vector3D getDirection() const;
  void setDirection(const Vector3D);
  
  void lookAt(Vector3D);
  
  Matrix4D getProjection();
  void setPerspective(GLfloat _angle, GLfloat _aspect, GLfloat _near, GLfloat _far);
  void setPerspective(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far);
};

#endif /* CameraController_hpp */
