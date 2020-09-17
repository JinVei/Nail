#pragma once
#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include "common/def.h"

namespace nail {
    class OpenglFrameBuffer {
    private:
        CLASS_NON_COPYABLE(OpenglFrameBuffer);
        GLuint _fbo = 0;
        GLuint _tbo = 0;
        GLuint _rbo = 0;

    public:
        OpenglFrameBuffer(float width, float height);
        virtual ~OpenglFrameBuffer();

        void apply();
        void unapply();
        GLuint getTbo();
    };
}