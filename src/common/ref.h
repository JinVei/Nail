
#pragma once
#include <memory>
#include <string>
#include <map>
#include <any>
namespace nail {
    template<typename Ty>
    using ref = std::shared_ptr<Ty>;
    
    using String = std::string;
    using ConstString = std::string_view;
    using Value = std::any;
    using ParamList = std::map<String,Value>;
}