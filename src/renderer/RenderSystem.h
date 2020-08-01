#pragma once
#include "common/ref.h"
#include "RenderVertexBufferFactory.h"

namespace nail {
    class RenderSystem {
        RenderSystem() = delete;
        static ref<RenderSystem> _singleton;
        ref<RenderVertexBufferFactory> _vertex_buffer_factory = nullptr;
    public:
        static ref<RenderSystem> getSingleton() {
            return _singleton;
        }
        static void setSingleton(ref<RenderSystem> singleton) {
            _singleton = singleton;
        }
        ref<RenderVertexBufferFactory> getRenderVertexBufferFactory() {
            return _vertex_buffer_factory;
        }

        void setRenderVertexBufferFactory(ref<RenderVertexBufferFactory> factory) {
            _vertex_buffer_factory = factory;
        }

    };
}

// RenderPhongLight(Cameras,Lights,Renderabls)
// RenderCanvas
