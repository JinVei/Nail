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
        void setData(std::vector<float>&& data) {
            _vertex_data = std::move(data);
        }
        void setData(const std::vector<float>& data) {
            _vertex_data = data;
        }
        std::vector<float>& getData() {
            return _vertex_data;
        }

        void setIndexData(std::vector<unsigned int>&& index_data) {
            _index_data = std::move(index_data);
        }
        void setIndexData(const std::vector<unsigned int>& index_data) {
            _index_data = index_data;
        }
        std::vector<unsigned int>& getIndexData() {
            return _index_data;
        }
    private:
        ref<VertexDataDescription> _vertex_descr;
        ref<RenderVertexBuffer> _render_vertex_buffer;
        std::vector<float> _vertex_data;
        std::vector<unsigned int> _index_data;
    };
}