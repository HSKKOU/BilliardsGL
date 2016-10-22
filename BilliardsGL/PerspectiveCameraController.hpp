//
//  CameraController.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/26.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef PerspectiveCameraController_hpp
#define PerspectiveCameraController_hpp

#include "GlobalHeader.h"
#include "CameraControllerBase.hpp"

NS_ENGINE_CAMERA

class PerspectiveCameraController : public CameraControllerBase {
  
public:
  PerspectiveCameraController(Transform t);
  virtual ~PerspectiveCameraController();
  
  void setPerspective(const GLfloat _fovy, const GLfloat _aspect, const GLfloat _zNear, const GLfloat _zFar);
//  void setPerspective(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far);

  virtual void translate(Vector3D dest);
  virtual void rotate(Quaternion rot);
  
protected:
  virtual void calcCameraTransform();
  virtual void calcProjectionMatrix(const GLfloat _fovy, const GLfloat _aspect, const GLfloat _zNear, const GLfloat _zFar);
  virtual void calcViewMatrix();
};

NS_END2

#endif /* PerspectiveCameraController_hpp */
