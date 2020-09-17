#pragma once
#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include "common/def.h"

namespace nail {
    class OpenglFrameBuffer {
    private:
        CLASS_NON_COPYABLE(OpenglFrameBuffer);
        GLuint _fbo;
        GLuint _rbo;

    public:
        OpenglFrameBuffer(float width, float height);
        virtual ~OpenglFrameBuffer();

        void apply();
        void unapply();
    };
}