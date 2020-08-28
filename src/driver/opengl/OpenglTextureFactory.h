#include "scene/TextureFactory.h"
#include "common/ref.h"

namespace nail {
    class TextureManager;

    class OpenglTextureFactory : public TextureFactory {
    private:
        wref<TextureManager> _manager;
    public:
        OpenglTextureFactory(wref<TextureManager> manager);
        ref<Texture> createTexture(String path) override;
        ref<Texture> createTexture(ref<ImageData>) override;
    };
}