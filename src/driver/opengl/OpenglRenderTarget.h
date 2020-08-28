#pragma once
#include "renderer/RenderTarget.h"
#include "common/vec.h"
#include "OpenglFrameBuffer.h"

#include <memory>

namespace nail {
    class OpenglRenderSystem;

    class OpenglRenderTarget : public RenderTarget {
    private:
        ViewPort _view_port;
        mat4 _projection_matrix;
        Color _clear_color;
        wref<OpenglRenderSystem> _render_system;
        ref<OpenglFrameBuffer> _frame_buffer;

    protected:
        //startFrame();
        //endFrame();
    public:
        OpenglRenderTarget(wref<OpenglRenderSystem> render_system, float width, float height);
        virtual ViewPort getViewPort();
        virtual void setViewPort(ViewPort);
        virtual void setupPerspective(float fovy, float near, float far);
        virtual void setClearColor(Color);
        virtual void render(std::vector<ref<IRenderable>>, std::list<ref<Light>>, mat4 view_matrix);
    };
}