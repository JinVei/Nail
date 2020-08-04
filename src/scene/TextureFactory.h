#pragma once
#include "common/ref.h"
#include "Texture.h"
#include "ImageLoader.h"

namespace nail {
    class TextureFactory {
    public:
        virtual ref<Texture> createTexture(String path) = 0;
        virtual ref<Texture> createTexture(ref<ImageData>) = 0;
    };
}