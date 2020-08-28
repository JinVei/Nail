#include "RenderSystem.h"
using namespace nail;

void RenderSystem::setRenderVertexBufferFactory(ref<RenderVertexBufferFactory> factory) {
    _vertex_buffer_factory = factory;
}

ref<RenderVertexBufferFactory> RenderSystem::getRenderVertexBufferFactory() {
    return _vertex_buffer_factory;
}

void RenderSystem::setSelf(wref<RenderSystem> self) {
    _self = self;
}