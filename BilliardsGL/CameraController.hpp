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

class CameraController : public Base3D {
  Vector3D center;
  Vector3D upDir;
  Matrix4D projection;
  
public:
  CameraController(Vector3D _pos, Vector3D _center, Vector3D _up = Vector3D::up());
  virtual ~CameraController();
  
  Matrix4D getViewMatrix();
  
  Vector3D getDirection();
  
  void lookAt(Vector3D);
  
  Matrix4D getProjection() const;
  void setPerspective(const GLfloat _fovy, const GLfloat _aspect, const GLfloat _zNear, const GLfloat _zFar);
  void setPerspective(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far);
};

#endif /* CameraController_hpp */
