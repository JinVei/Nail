#pragma once
#include "ResourceManager.h"
#include "ImageLoader.h"
#include "Texture.h"

namespace nail {
    class TextureManager : public ResourceManager {
    private:
        ref<ImageLoader> _image_loader;
    public:
        ref<Texture> retrieveOrCreate(String Path);
        ref<ImageLoader> getImageLoader();
    };
    
} // namespace nail
