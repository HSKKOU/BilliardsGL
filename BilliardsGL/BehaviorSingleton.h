//
//  BehaviorSingleton.hpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/10/23.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef BehaviorSingleton_hpp
#define BehaviorSingleton_hpp

#include "ObjectBehavior.hpp"

NS_ENGINE_UTIL

template<class T>
class BehaviorSingleton : public ObjectBehavior {
  
public:
  // singleton accessor
  static T& instance() {
    static typename T::singleton_pointer_type s_singleton(T::createInstance());
    return getReference(s_singleton);
  }
  
private:
  // single instance pointer
  typedef std::unique_ptr<T> singleton_pointer_type;
  
  inline static T *createInstance() { return new T(); }
  inline static T &getReference(const singleton_pointer_type &ptr) { return *ptr; }
  
protected:
  BehaviorSingleton() {}
  virtual ~BehaviorSingleton() {}
  
private:
  // copy and move prohibition
  BehaviorSingleton(const BehaviorSingleton &) = delete;
  BehaviorSingleton& operator=(const BehaviorSingleton &) = delete;
  BehaviorSingleton(BehaviorSingleton &&) = delete;
  BehaviorSingleton& operator=(BehaviorSingleton &&) = delete;
};

NS_END2

#endif /* BehaviorSingleton_hpp */
