#include "assert.h"
#include "backtrace.h"
#include <iostream>
namespace jv {
inline namespace v1 {
  void assert_faild(const char* assertion, const char* file, int line, const char* func){
    std::cerr << "assert failed: " << assertion << std::endl;
#ifdef __GNUC__
    std::cerr << "thread id: " << (unsigned long long)pthread_self() << std::endl;
#endif
    std::cerr << file << "\t" << line << "\t" << func << std::endl;
    Backtrace bt;
    bt.print(std::cerr);
    std::cerr.flush();
    std::abort();
  }
} // v1
}