#pragma once
#include "ResourceManager.h"
#include "ImageLoader.h"
#include "Texture.h"
#include "TextureFactory.h"

namespace nail {
    class TextureManager : public ResourceManager {
    private:
        ref<ImageLoader> _image_loader;
        ref<TextureFactory> _texture_factory;
        wref<TextureManager> _self;

    public:
        TextureManager();
        void setSelf(wref<TextureManager>);
        void setImageLoader(ref<ImageLoader>);
        void setTextureFactory(ref<TextureFactory>);

        ref<Texture> retrieveOrCreate(String Path);
        ref<ImageLoader> getImageLoader();
    };
    
} // namespace nail
