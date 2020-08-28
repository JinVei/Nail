#include "OpenglTextureFactory.h"
#include "scene/TextureManager.h"
#include "OpenglTexture2D.h"
#include "common/assert.h"

using namespace nail;

OpenglTextureFactory::OpenglTextureFactory(wref<TextureManager> manager) {
    _manager = manager;
}

ref<Texture> OpenglTextureFactory::createTexture(String path) {
    auto manager = _manager.lock();
    NAIL_ASSERT(manager != nullptr);

    ref<ImageData> image_data = manager->getImageLoader()->load(path.c_str());
    return createTexture(image_data);
}

ref<Texture> OpenglTextureFactory::createTexture(ref<ImageData> image_data) {
    auto texture = ref<OpenglTexture2D>(new OpenglTexture2D());
    texture->load(image_data);
    return texture;
}