#pragma once
#include "common/ref.h"
#include "RenderVertexBufferFactory.h"
#include "RenderTarget.h"

namespace nail {
    class RenderSystem {
    protected:
        wref<RenderSystem> _self;
        ref<RenderVertexBufferFactory> _vertex_buffer_factory = nullptr;

    protected:

    public:
        RenderSystem() {};
        virtual ~RenderSystem() {};
        void setRenderVertexBufferFactory(ref<RenderVertexBufferFactory> factory);
        ref<RenderVertexBufferFactory> getRenderVertexBufferFactory();

        void setSelf(wref<RenderSystem>);
        virtual bool setup() = 0;
        virtual void enableDeepTest() = 0;
        virtual void swapActiveBuffers() = 0;
        virtual ref<RenderTarget> createRenderTarget(float width, float height) = 0;
    };
}
