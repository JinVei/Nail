#pragma once
#include "Resource.h"
namespace nail {
    class Texture: public Resource {
    public:
        std::string _filPath;
        uint64_t _width;
        uint64_t _hight;
    };
}