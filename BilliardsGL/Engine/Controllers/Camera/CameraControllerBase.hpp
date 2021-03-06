//
//  CameraControllerBase.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/18.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef CameraControllerBase_hpp
#define CameraControllerBase_hpp

#include "Base3D.h"

NS_ENGINE_CAMERA

class CameraControllerBase : public Base3D {
protected:
  Matrix4D projectionMatrix;
  Matrix4D viewMatrix;
  
public:
  CameraControllerBase(Transform t);
  virtual ~CameraControllerBase();
  
  Vector3D getDirection();
  
  Matrix4D getProjectionMatrix() const;
  
  Matrix4D getViewMatrix() const;
  virtual void translateTo(Vector3D dest);
  virtual void rotation(Quaternion rot);

  virtual void translate(Vector3D delta);
  virtual void rotate(Quaternion rot);
  
protected:
  virtual void calcProjectionMatrix(const GLfloat _fovy, const GLfloat _aspect, const GLfloat _zNear, const GLfloat _zFar) = 0;
  virtual void calcViewMatrix() = 0;
};

NS_END2

#endif /* CameraControllerBase_hpp */
