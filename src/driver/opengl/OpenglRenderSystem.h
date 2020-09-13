#pragma once
#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include "renderer/RenderSystem.h"
#include "OpenglRenderTarget.h"
#include "OpenglFrameBuffer.h"
#include "common/GUID.h"
#include "OpenglShaderPhongLight.h"

namespace nail{
    class OpenglRenderSystem : public RenderSystem {
    private:
        friend class Contex;

        GLFWwindow* _window;
        std::map<GUID, ref<OpenglRenderTarget>> _render_targets;
        ref<OpenglShaderPhongLight> _phong_light_shader;

    public:
        OpenglRenderSystem();
        wref<OpenglRenderSystem> self();
        bool setup() override;
        void enableDeepTest() override;
        void swapActiveBuffers() override;

        ref<RenderTarget> createRenderTarget(float width, float height) override;
        ref<OpenglFrameBuffer> createFrameBuffer(float width, float height);
        ref<OpenglShaderPhongLight> getPhongLightShader();
        void drawTriangle(GLint first, GLsizei count);
        void DrawElements(size_t size);

        bool windowShouldClose() override;
    };
} // namespace nail