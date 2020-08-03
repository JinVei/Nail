#pragma once
#include "common/ref.h"
#include "RenderVertexBufferFactory.h"
#include "scene/Context.h"

namespace nail {
    class RenderSystem {
        friend class nail::Context;
    private:
        RenderSystem() {};
        static ref<RenderSystem> _singleton;
        ref<RenderVertexBufferFactory> _vertex_buffer_factory = nullptr;

        static void setSingleton(ref<RenderSystem> singleton);
    public:
        void setRenderVertexBufferFactory(ref<RenderVertexBufferFactory> factory);
        static ref<RenderSystem> singleton();
        ref<RenderVertexBufferFactory> getRenderVertexBufferFactory();
    };
}

// RenderPhongLight(Cameras,Lights,Renderabls)
// RenderCanvas
