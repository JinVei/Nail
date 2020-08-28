#pragma once
#include "common/ref.h"
#include "RenderVertexBufferFactory.h"

namespace nail {
    class RenderSystem {
    private:
        static ref<RenderSystem> _singleton;
        ref<RenderVertexBufferFactory> _vertex_buffer_factory = nullptr;

    protected:

    public:
        RenderSystem() {};
        virtual ~RenderSystem() {};
        void setRenderVertexBufferFactory(ref<RenderVertexBufferFactory> factory);
        ref<RenderVertexBufferFactory> getRenderVertexBufferFactory();

        virtual bool setup() = 0;
        virtual void enableDeepTest() = 0;
        virtual void swapActiveBuffers() = 0;
    };
}
