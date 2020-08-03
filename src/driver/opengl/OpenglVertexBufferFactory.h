#include "renderer/RenderVertexBufferFactory.h"

namespace nail {
    class OpenglVertexBufferFactory : public RenderVertexBufferFactory {
    public:
        virtual ref<RenderVertexBuffer> createVertexBuffer(VertexDataDescription descr, float* vertex_buffer, unsigned int* indices_buffer) override;
    };
}