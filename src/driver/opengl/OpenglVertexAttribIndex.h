#pragma once
#include "glad/glad.h"

namespace nail {
    enum struct OpenglVertexAttribIndex : GLuint{
        Vertex = 0,
        TextureCoord,
        Normal,
        Tangent,
        Bitangent,
    };
}