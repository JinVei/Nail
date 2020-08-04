#include "scene/TextureFactory.h"

namespace nail {
    class OpenglTextureFactory : public TextureFactory {
    public:
        ref<Texture> createTexture(String path) override;
        ref<Texture> createTexture(ref<ImageData>) override;
    };
}