#pragma once
#include <cstdint>

namespace nail {
    class VertexDataDescription {
    public:
        int64_t _vertex_num = -1;
        int64_t _vertex_indices_num = -1;
        int64_t _vertex_offset = -1;
        int64_t _normal_offset = -1;
        int64_t _texture_coord_offset = -1;
        int64_t _tangent_offset = -1;
        int64_t _bitangent_offset = -1;
    };
}