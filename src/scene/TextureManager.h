#pragma once
#include "ResourceManager.h"
#include "ImageLoader.h"
#include "Texture.h"
#include "Context.h"
#include "TextureFactory.h"

namespace nail {
    class TextureManager : public ResourceManager {
        friend class Context;
    private:
        TextureManager();
        ref<ImageLoader> _image_loader;
        ref<TextureFactory> _texture_factory;
        static ref<TextureManager> _instance;
    protected:
        void setImageLoader(ref<ImageLoader>);
        static void setInstance(ref<TextureManager>);
        void setTextureFactory(ref<TextureFactory>);
    public:
        ref<Texture> retrieveOrCreate(String Path);
        ref<ImageLoader> getImageLoader();
        static ref<TextureManager> getInstance();
    };
    
} // namespace nail
