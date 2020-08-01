#pragma once
#include "common/ref.h"
#include "RenderVertexBuffer.h"
#include "scene/VertexDataDescription.h"

namespace nail {
    class RenderVertexBufferFactory {
    public:
        virtual ref<RenderVertexBuffer> createVertexBuffer(VertexDataDescription descr, const float* vertex_buffer, unsigned int* indices_buffer) = 0;
    };
}