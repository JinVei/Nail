#pragma once
#include "glad/glad.h"
#include <GLFW/glfw3.h>

namespace nail {
    class OpenglFrameBuffer {
    private:
        OpenglFrameBuffer& operator= (const OpenglFrameBuffer& right) = delete;
        OpenglFrameBuffer(const OpenglFrameBuffer& right) = delete;

        GLuint _fbo;
        GLuint _rbo;

    public:
        OpenglFrameBuffer(float width, float height);
        virtual ~OpenglFrameBuffer();

        void apply();
        void unapply();
    };
}