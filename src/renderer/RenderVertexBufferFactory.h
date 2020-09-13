#pragma once
#include "common/ref.h"
#include "RenderVertexBuffer.h"
#include "scene/VertexDataDescription.h"
#include <vector>

namespace nail {
    class RenderVertexBufferFactory {
    public:
        virtual ref<RenderVertexBuffer> 
        createVertexBuffer(VertexDataDescription descr, std::vector<float>& vertex_buffer,
                            std::vector<unsigned int>& indices_buffer) = 0;
        virtual ~RenderVertexBufferFactory() = default;
    };
}