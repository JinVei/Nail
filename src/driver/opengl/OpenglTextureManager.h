
#include "common/ref.h"
#include "scene/TextureManager.h"

namespace nail {

    class OpenglTextureManager : public TextureManager {
    public:
        OpenglTextureManager();
        void setSelf(wref<OpenglTextureManager> self);
        ref<Texture> createTexture(String path) override;
        ref<Texture> createTexture(ref<ImageData>) override;
    };
}