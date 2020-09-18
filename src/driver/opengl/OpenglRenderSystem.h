#pragma once
#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include "renderer/RenderSystem.h"
#include "OpenglRenderTarget.h"
#include "OpenglFrameBuffer.h"
#include "OpenglVertexBuffer.h"
#include "OpenglShaderScreen.h"

#include "common/GUID.h"
#include "OpenglShaderPhongLight.h"

namespace nail{
    class OpenglRenderSystem : public RenderSystem {
    private:
        friend class Contex;

        GLFWwindow* _window;
        std::map<GUID, ref<OpenglRenderTarget>> _render_targets;
        ref<OpenglShaderPhongLight> _phong_light_shader;
        String phong_light_vertex_shader_path = "./shader/phong_light_vertex.glsl";
        String phong_light_fragment_shader_path = "./shader/phong_light_fragment.glsl";

        ref<OpenglShaderScreen> _screen_shader;
        String screen_vertex_shader_path = "./shader/screen_vertex.glsl";
        String screen_frag_shader_path = "./shader/screen_fragment.glsl";

        ref<VertexData> _screen_vertex_data;
    private:
        void _setupScreenVertexData();
    public:
        OpenglRenderSystem();
        wref<OpenglRenderSystem> self();
        bool setup() override;
        void enableDepthTest();
        void swapActiveBuffers() override;

        ref<RenderTarget> createRenderTarget(float width, float height) override;
        ref<OpenglFrameBuffer> createFrameBuffer(float width, float height);
        ref<OpenglShaderPhongLight> getPhongLightShader();
        ref<OpenglShaderScreen> getScreenShader();

        bool windowShouldClose() override;
        virtual void rasterize(ref<OpenglVertexBuffer>, ref<VertexDataDescription>, ref<OpenglShader>);
        void render() override;
    };
} // namespace nail