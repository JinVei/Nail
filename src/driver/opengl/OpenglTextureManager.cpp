#include "OpenglTextureFactory.h"
#include "scene/TextureManager.h"
#include "OpenglTexture2D.h"
#include "common/assert.h"
#include "OpenglTextureManager.h"

using namespace nail;

OpenglTextureManager::OpenglTextureManager() {

}

void OpenglTextureManager::setSelf(wref<OpenglTextureManager> self) {
    _self = self;
}

ref<Texture> OpenglTextureManager::createTexture(String path) {
    ref<ImageLoader> image_loader = getImageLoader();
    NAIL_ASSERT(image_loader != nullptr);

    ref<ImageData> image_data = getImageLoader()->load(path.c_str());
    return createTexture(image_data);
}

ref<Texture> OpenglTextureManager::createTexture(ref<ImageData> image_data) {
    auto texture = ref<OpenglTexture2D>(new OpenglTexture2D());
    texture->load(image_data);
    return texture;
}