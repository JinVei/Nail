#pragma once
#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include "renderer/RenderSystem.h"
#include "OpenglRenderTarget.h"
#include "OpenglFrameBuffer.h"
#include "OpenglVertexBuffer.h"

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
        void enableDepthTest();
        void swapActiveBuffers() override;

        ref<RenderTarget> createRenderTarget(float width, float height) override;
        ref<OpenglFrameBuffer> createFrameBuffer(float width, float height);
        ref<OpenglShaderPhongLight> getPhongLightShader();

        bool windowShouldClose() override;
        virtual void rasterize(ref<OpenglVertexBuffer>, ref<VertexDataDescription>, ref<OpenglShader>);
    };
} // namespace nail