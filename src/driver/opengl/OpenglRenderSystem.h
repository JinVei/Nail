#pragma once
#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include "renderer/RenderSystem.h"
#include "OpenglRenderTarget.h"
#include "OpenglFrameBuffer.h"
#include "common/GUID.h"

namespace nail{
    class OpenglRenderSystem : public RenderSystem {
    private:
        friend class Contex;

        GLFWwindow* _window;
        std::map<GUID, ref<OpenglRenderTarget>> _render_targets;
        wref<OpenglRenderSystem> _wthis;

        void setWThis(wref<OpenglRenderSystem>);
    public:
        OpenglRenderSystem();
        bool setup() override;
        void enableDeepTest() override;
        void swapActiveBuffers() override;

        ref<OpenglRenderTarget> createRenderTarget(float width, float height);
        ref<OpenglFrameBuffer> createFrameBuffer(float width, float height);
    };
} // namespace nail