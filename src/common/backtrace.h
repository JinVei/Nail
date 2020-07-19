#pragma once
#ifdef __GNUC__
#include <execinfo.h>
#endif
#include <stdlib.h>
#include <ostream>

//#include <cxxabi.h>
namespace jv {
  struct Backtrace {
    const static int max_tier_ = 100;
    void* buffer_[max_tier_] = {nullptr};
    int tier_ = {0};
    char** info_ = {nullptr};
  public:
    explicit Backtrace(int tier = max_tier_) {
#ifdef __GNUC__
      tier_ = backtrace(buffer_, (tier < max_tier_ ? tier : max_tier_));
      info_ = backtrace_symbols(buffer_, tier_);
#endif
    }
    ~Backtrace() {
      free(info_);
    }
    void print(std::ostream& out){
      for( int i=0; i < tier_; ++i) {
        //buff = abi::__cxa_demangle(/*info_[i]*/"_ZN9wikipedia7article6formatB5cxx11Ev",buff, &buff_size, &status);
        out << info_[i] <<std::endl;
      }
    }
  };
}