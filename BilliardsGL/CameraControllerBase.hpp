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
  Vector3D center;
  Vector3D upDir;
  Matrix4D projectionMatrix;
  Matrix4D viewMatrix;
  
public:
  CameraControllerBase(Vector3D _pos, Vector3D _center, Vector3D _up = Vector3D::up());
  virtual ~CameraControllerBase();
  
  Vector3D getDirection();
  
  Matrix4D getProjectionMatrix() const;
  
  Matrix4D getViewMatrix() const;
  virtual void translate(Vector3D dest);
  virtual void rotate(Quaternion rot);
  
protected:
  virtual void calcProjectionMatrix(const GLfloat _fovy, const GLfloat _aspect, const GLfloat _zNear, const GLfloat _zFar) = 0;
  virtual void calcViewMatrix() = 0;
};

NS_END2

#endif /* CameraControllerBase_hpp */
