#include "TextureManager.h"
#include "common/assert.h"

using namespace nail;

TextureManager::TextureManager(){}

void TextureManager::setSelf(wref<TextureManager> self) {
    _self = self;
}

ref<ImageLoader> TextureManager::getImageLoader() {
    return _image_loader;
}

ref<Texture> TextureManager::retrieveOrCreate(String path) {
    ref<ImageData> image_data = ref_cast<ImageData>(getResource(path));
    if (image_data == nullptr) {
        image_data = _image_loader->load(path.c_str());
        NAIL_ASSERT(image_data != nullptr);
        saveResource(path, image_data);
    }
    NAIL_ASSERT(image_data != nullptr);
    auto texture_ptr =  createTexture(image_data);
    return texture_ptr;
}

void TextureManager::setImageLoader(ref<ImageLoader> image_loader) {
    _image_loader = image_loader;
}

// void TextureManager::setTextureFactory(ref<TextureFactory> factory) {
//     _texture_factory = factory;
// }