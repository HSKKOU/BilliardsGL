//
//  BaseObject3D.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/22.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef BaseObject3D_hpp
#define BaseObject3D_hpp

#include <vector>

#include "Base3D.h"
#include "BaseModel3D.hpp"
#include "ObjectBehavior.hpp"

US_NS_ENGINE_MODEL

NS_ENGINE

struct ShaderPair {
  const char* vert = "Shaders/Project/test/LightTest.vert";
  const char* frag = "Shaders/Project/test/LightTest.frag";
  ShaderPair() { /* do nothing */ }
};

struct Surface {
  ETex texture;
  Color color;
  ShaderPair shaders;
  Surface(ETex tex = ETex::None, Color c = Color::one(), ShaderPair sp = ShaderPair())
  : texture(tex)
  , color(c)
  , shaders(sp)
  { /* do nothing */ }
};

class BaseObject3D : public Base3D, public ObjectBehavior {
protected:
  std::vector<BaseModel3D*> modelList;
  Surface surface;

  
public:
  BaseObject3D();
  BaseObject3D(Transform t, Surface surf);
  virtual ~BaseObject3D();
    
  virtual void awake();
  virtual void start();
  virtual void update(GLfloat deltaTime);
  virtual void lateUpdate(GLfloat deltaTime);
  virtual void draw();
  virtual void destroy();
  
  void setTransform(Transform trsf);
  void setColor(Color c);
  Color getColor() const;
  
  virtual void translateTo(Vector3D dest);
  virtual void rotation(Quaternion rot);
  virtual void scale(Vector3D scl);
  
  virtual void translate(Vector3D delta);
  virtual void rotate(Quaternion rot);

protected:
  virtual BaseModel3D* createModel() = 0;
  BaseModel3D* createModelWithSetSurface();
};

NS_END

#endif /* BaseObject3D_hpp */
