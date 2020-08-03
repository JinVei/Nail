#pragma once
#include "Resource.h"
namespace nail {
    class Texture: public Resource {
    public:
        enum class TextureType {
            TEXTURE_2D,
        };
        virtual ~Texture() {}
        uint64_t _width;
        uint64_t _hight;

        int _channel;
        TextureType _type;
    };
}