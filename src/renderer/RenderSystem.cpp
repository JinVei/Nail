#include "RenderSystem.h"
using namespace nail;

ref<RenderSystem> RenderSystem::_singleton = nullptr;

void RenderSystem::setRenderVertexBufferFactory(ref<RenderVertexBufferFactory> factory) {
    _vertex_buffer_factory = factory;
}
ref<RenderSystem> RenderSystem::singleton() {
    return _singleton;
}
void RenderSystem::setSingleton(ref<RenderSystem> singleton) {
    _singleton = singleton;
}
ref<RenderVertexBufferFactory> RenderSystem::getRenderVertexBufferFactory() {
    return _vertex_buffer_factory;
}
