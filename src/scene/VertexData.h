#pragma once
#include "common/ref.h"
#include "renderer/RenderVertexBuffer.h"
#include "VertexDataDescription.h"
#include <vector>

namespace nail {
    class VertexData {
    public:
        ref<VertexDataDescription> getVertexDataDescription() {
            return _vertex_descr;
        }
        void setVertexDataDescription(ref<VertexDataDescription> descr) {
            _vertex_descr = descr;
        }
        void setRenderVertexBuffer(ref<RenderVertexBuffer> buffer) {
            _render_vertex_buffer = buffer;
        }
        ref<RenderVertexBuffer> getRenderVertexBuffer() {
            return _render_vertex_buffer;
        }
    private:
        ref<VertexDataDescription> _vertex_descr;
        ref<RenderVertexBuffer> _render_vertex_buffer;
    };
}