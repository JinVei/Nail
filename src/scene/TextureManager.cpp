#include "TextureManager.h"

using namespace nail;

ref<TextureManager> TextureManager::_instance = nullptr;

TextureManager::TextureManager(){}

void TextureManager::setInstance(ref<TextureManager> instance) {
    _instance = instance;
}

ref<TextureManager> TextureManager::getInstance() {
    return _instance;
}

ref<ImageLoader> TextureManager::getImageLoader() {
    return _image_loader;
}

ref<Texture> TextureManager::retrieveOrCreate(String path) {
    ref<ImageData> image_data = std::dynamic_pointer_cast<ImageData>(getResource(path));
    if (image_data != nullptr) {

    }
}

void TextureManager::setImageLoader(ref<ImageLoader> image_loader) {
    _image_loader = image_loader;
}

void TextureManager::setTextureFactory(ref<TextureFactory> factory) {
    _texture_factory = factory;
}