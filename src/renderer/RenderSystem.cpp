#include "RenderSystem.h"
using namespace nail;

ref<RenderSystem> RenderSystem::_singleton = nullptr;

void RenderSystem::setRenderVertexBufferFactory(ref<RenderVertexBufferFactory> factory) {
    _vertex_buffer_factory = factory;
}

ref<RenderVertexBufferFactory> RenderSystem::getRenderVertexBufferFactory() {
    return _vertex_buffer_factory;
}
