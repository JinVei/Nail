#pragma once
#include "renderer/RenderTarget.h"
#include "common/vec.h"
#include "OpenglFrameBuffer.h"

#include <memory>

namespace nail {
    class OpenglRenderSystem;

    class OpenglRenderTarget : public RenderTarget {
    private:
        float _width;
        float _height;
        ViewPort _view_port;
        mat4 _projection_matrix;
        Color _clear_color = {0.1f, 0.1f, 0.1f, 0.1f};
        wref<OpenglRenderSystem> _render_system;
        ref<OpenglFrameBuffer> _frame_buffer;
        bool _enable_depth_test = true;
    protected:
        //startFrame();
        //endFrame();
    public:
        OpenglRenderTarget(wref<OpenglRenderSystem> render_system, float width, float height);
        virtual ViewPort getViewPort() override;
        virtual void setViewPort(ViewPort) override;
        virtual void setupPerspective(float fovy, float near, float far) override;
        virtual void setClearColor(Color) override;
        virtual void render(std::vector<ref<IRenderable>>, std::list<ref<Light>>, mat4 view_matrix, vec3 view_pos) override;
        void enableDepthTest(bool) override;
        GLuint getRenderTargetTbo();
    };
}