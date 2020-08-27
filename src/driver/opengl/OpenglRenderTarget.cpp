#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include "common/assert.h"
#include "OpenglRenderTarget.h"
#include "OpenglRenderSystem.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace nail;

OpenglRenderTarget:: OpenglRenderTarget(wref<OpenglRenderSystem> render_system, float width, float height) {
    _render_system = render_system;
    auto render_system_ref = _render_system.lock();
    NAIL_ASSERT(render_system_ref != nullptr);

    _frame_buffer = render_system_ref->createFrameBuffer(width, height);
}

RenderTarget::ViewPort OpenglRenderTarget::getViewPort() {
    return _view_port;
}

void OpenglRenderTarget::setViewPort(ViewPort view_port) {
    _view_port = view_port;
}

void OpenglRenderTarget::setupPerspective(float fovy, float near, float far) {
    _projection_matrix =  glm::perspective(fovy, _view_port.width/_view_port.height, near, far);
}

void OpenglRenderTarget::setClearColor(Color color) {
    _clear_color = color;
}

void OpenglRenderTarget::render(std::vector<ref<IRenderable>>, std::list<ref<Light>>, mat4 view_matrix) {
    glViewport(_view_port.x, _view_port.x, _view_port.width, _view_port.height);
    auto render_system = _render_system.lock();
    NAIL_ASSERT(render_system != nullptr);
    //TODO
    render_system->swapActiveBuffers();
}