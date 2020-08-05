#pragma once
#include "common/ref.h"
#include "RenderVertexBufferFactory.h"
#include "scene/Context.h"

namespace nail {
    class RenderSystem {
        friend class nail::Context;
    private:
        static ref<RenderSystem> _singleton;
        ref<RenderVertexBufferFactory> _vertex_buffer_factory = nullptr;

    protected:
        RenderSystem() {};
        static void setSingleton(ref<RenderSystem> singleton);

    public:
        void setRenderVertexBufferFactory(ref<RenderVertexBufferFactory> factory);
        static ref<RenderSystem> getSingleton();
        ref<RenderVertexBufferFactory> getRenderVertexBufferFactory();

        virtual bool setup() = 0;
        virtual void enableDeepTest() = 0;
        virtual void swapActiveBuffers() = 0;
    };
}
