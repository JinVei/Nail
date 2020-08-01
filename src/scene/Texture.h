#pragma once
#include "Resource.h"
namespace nail {
    class Texture: public Resource {
    public:
        enum class TextureType {

        };
        uint64_t _width;
        uint64_t _hight;

        int _channel;
        TextureType _type;
    };
}