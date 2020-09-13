#pragma once
#include <cstdint>

namespace nail {
    class VertexDataDescription {
    public:
        const int64_t unset = -1;
        int64_t _vertex_num = unset;
        int64_t _vertex_indices_num = unset;
        int64_t _vertex_offset = unset;
        int64_t _normal_offset = unset;
        int64_t _texture_coord_offset = unset;
        int64_t _tangent_offset = unset;
        int64_t _bitangent_offset = unset;
        int64_t _stride = unset;

        // size of per vertex
        int64_t _vertex_size = unset;
        int64_t _normal_size = unset;
        int64_t _texture_coord_size = unset;
        int64_t _tangent_size = unset;
        int64_t _bitangent_size = unset;

    };
}