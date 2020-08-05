#pragma once
#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include "renderer/RenderSystem.h"

namespace nail{
    class OpenglRenderSystem : public RenderSystem {
    private:
        GLFWwindow* _window;
    public:
        OpenglRenderSystem();
        bool setup() override;
        void enableDeepTest() override;
        void swapActiveBuffers() override;
    };
} // namespace nail