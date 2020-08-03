#pragma once
#include "renderer/RenderVertexBuffer.h"
#include <stdint.h>
#include "glad/glad.h"

namespace nail {
    class OpenglVertexBuffer : public RenderVertexBuffer {
    private:
        GLuint _VBO = 0;
        GLuint _VAO = 0;
        GLuint _EBO = 0;
        bool _hasEBO = false;
    public:
        OpenglVertexBuffer(float* vertices, unsigned int size);
        ~OpenglVertexBuffer();
        void setIndices(unsigned int* indices, unsigned int size);
        void setAttribPointer(GLuint loc, unsigned int size, unsigned int step, GLuint offset);
        void apply();
        void unapply();
        bool hasIndexBuffer();
    };
}