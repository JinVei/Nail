#pragma once

namespace jv {

inline namespace v1 {
#ifdef _MSC_VER // Visual Studio
  #define __JV_ASSERT_FUNCTION __FUNCTION__
#elif defined(__GNUC__)
  # define __JV_ASSERT_FUNCTION __PRETTY_FUNCTION__
#else
  # define __JV_ASSERT_FUNCTION ((__const char *) "")
#endif

  extern void assert_faild(const char* assertion, const char* file_name, int line, const char* func_name);
  #define _TO_STRING(x) #x
  #define JV_ASSERT(expr) do { (expr) ? static_cast<void>(0) : jv::assert_faild(_TO_STRING(expr), __FILE__, __LINE__, __JV_ASSERT_FUNCTION); } while(false)
  #define NAIL_ASSERT JV_ASSERT
}// v1
}