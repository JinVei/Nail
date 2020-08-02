#pragma once
#include "common/ref.h"
#include "RenderVertexBufferFactory.h"
#include "scene/Context.h"

namespace nail {
    class RenderSystem {
        friend class nail::Context;

        void setRenderVertexBufferFactory(ref<RenderVertexBufferFactory> factory) {
            _vertex_buffer_factory = factory;
        }

    private:
        RenderSystem() {};
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
    };
}

// RenderPhongLight(Cameras,Lights,Renderabls)
// RenderCanvas
