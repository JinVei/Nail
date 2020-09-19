#include "assert.h"
//#include "backtrace.h"
#include <boost/stacktrace.hpp>
#include <iostream>
namespace jv {
inline namespace v1 {
  void assert_faild(const char* assertion, const char* file, int line, const char* func){
    std::cerr << "Assert failed: " << assertion << std::endl;
#ifdef __GNUC__
    std::cerr << "thread id: " << (unsigned long long)pthread_self() << std::endl;
#endif
    std::cerr << file << "\t" << line << "\t" << func << std::endl;
    //Backtrace bt;
    //bt.print(std::cerr);
    std::cerr << boost::stacktrace::stacktrace();
    std::cerr.flush();
    std::abort();
  }
} // v1
}