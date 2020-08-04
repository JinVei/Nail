#include "TextureManager.h"

using namespace nail;

ref<ImageLoader> TextureManager::getImageLoader() {
    return _image_loader;
}

ref<Texture> TextureManager::retrieveOrCreate(String path) {
    getResource(path);
}