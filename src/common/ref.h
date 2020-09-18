
#pragma once
#include <memory>
#include <string>
#include <map>
//#include <any>
namespace nail {
    template<typename Ty>
    using ref = std::shared_ptr<Ty>;

    template<typename Ty>
    using wref = std::weak_ptr<Ty>;
    
    using String = std::string;
    using ConstString = std::string_view;
//    using Value = std::any;
    using ParamList = std::map<ConstString,String>;

    template <typename T, typename U> 
    inline ref<T> ref_cast(const ref<U> &r) noexcept {
        return std::dynamic_pointer_cast<T>(r);
    }

    template <typename T, typename... args_t> 
    inline ref<T> ref_create(args_t... args) noexcept {
        return ref<T>(new T(args...));
    }
}