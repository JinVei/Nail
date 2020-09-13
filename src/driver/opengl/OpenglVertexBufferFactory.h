#include "renderer/RenderVertexBufferFactory.h"

namespace nail {
    class OpenglVertexBufferFactory : public RenderVertexBufferFactory {
    public:
        virtual ref<RenderVertexBuffer> 
        createVertexBuffer(VertexDataDescription descr, 
                            std::vector<float>& vertex_buffer,
                            std::vector<unsigned int>& indices_buffer) override;
    };
}