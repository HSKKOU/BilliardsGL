//
//  Singleton.h
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/15.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#ifndef Singleton_h
#define Singleton_h

#include "GlobalHeader.h"
#include <memory>

NS_ENGINE_UTIL

template<class T>
class Singleton {
  
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
  Singleton() {}
  virtual ~Singleton() {}
  
private:
  // copy and move prohibition
  Singleton(const Singleton &) = delete;
  Singleton& operator=(const Singleton &) = delete;
  Singleton(Singleton &&) = delete;
  Singleton& operator=(Singleton &&) = delete;
};

NS_END2

#endif /* Singleton_h */
