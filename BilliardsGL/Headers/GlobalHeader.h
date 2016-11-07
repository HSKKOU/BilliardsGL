//
//  GlobalHeader.h
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/15.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef GlobalHeader_h
#define GlobalHeader_h

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

// namespaces
#define NS_ENGINE               namespace Engine {
#define NS_ENGINE_MODEL         namespace Engine { namespace Model {
#define NS_ENGINE_UTIL          namespace Engine { namespace Util {

#define NS_ENGINE_LIGHT         namespace Engine { namespace Light {
#define NS_ENGINE_CAMERA        namespace Engine { namespace Camera {

#define NS_GAME                 namespace Game {



#define US_NS_ENGINE            using namespace Engine;
#define US_NS_ENGINE_MODEL      using namespace Engine::Model;
#define US_NS_ENGINE_UTIL       using namespace Engine::Util;
#define US_NS_ENGINE_LIGHT      using namespace Engine::Light;
#define US_NS_ENGINE_CAMERA     using namespace Engine::Camera;

#define US_NS_GAME              using namespace Game;




#define NS_END                  }
#define NS_END2                 }}


#endif /* GlobalHeader_h */
