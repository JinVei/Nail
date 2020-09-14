#pragma once
#include "glad/glad.h"
#include "renderer/RenderVertexBuffer.h"
#include <stdint.h>
#include <vector>

namespace nail {
    class OpenglVertexBuffer : public RenderVertexBuffer {
    private:
        GLuint _VBO = 0;
        GLuint _VAO = 0;
        GLuint _EBO = 0;
        bool _hasEBO = false;
    public:
        OpenglVertexBuffer(const std::vector<float>& vertices);
        ~OpenglVertexBuffer();
        void setIndices(const std::vector<unsigned int>& indices);
        void setAttribPointer(GLuint loc, unsigned int size, unsigned int step, GLuint offset);
        void apply();
        void unapply();
        bool hasIndexBuffer();
    };
}