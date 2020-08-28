#pragma once
#include "ResourceManager.h"
#include "ImageLoader.h"
#include "Texture.h"
#include "TextureFactory.h"

namespace nail {
    class TextureManager : public ResourceManager {
    protected:
        ref<ImageLoader> _image_loader;
        wref<TextureManager> _self;

    public:
        TextureManager();
        void setSelf(wref<TextureManager>);
        void setImageLoader(ref<ImageLoader>);
        //void setTextureFactory(ref<TextureFactory>);

        ref<Texture> retrieveOrCreate(String Path);
        ref<ImageLoader> getImageLoader();

        virtual ref<Texture> createTexture(String path) = 0;
        virtual ref<Texture> createTexture(ref<ImageData>) = 0;
    };
    
} // namespace nail
