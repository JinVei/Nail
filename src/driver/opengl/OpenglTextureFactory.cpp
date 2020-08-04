#include "OpenglTextureFactory.h"
#include "scene/TextureManager.h"
#include "OpenglTexture2D.h"
using namespace nail;

ref<Texture> OpenglTextureFactory::createTexture(String path) {
    ref<ImageData> image_data = TextureManager::getInstance()->getImageLoader()->load(path.c_str());
    return createTexture(image_data);
}

ref<Texture> OpenglTextureFactory::createTexture(ref<ImageData> image_data) {
    auto texture = ref<OpenglTexture2D>(new OpenglTexture2D());
    texture->load(image_data);
    return texture;
}