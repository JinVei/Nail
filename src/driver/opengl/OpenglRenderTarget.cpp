#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include "common/assert.h"
#include "OpenglRenderTarget.h"
#include "OpenglRenderSystem.h"
#include "OpenglVertexBuffer.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace nail;

OpenglRenderTarget:: OpenglRenderTarget(wref<OpenglRenderSystem> render_system, float width, float height) {
    _width = width;
    _height = height;

    _render_system = render_system;
    auto render_system_ref = _render_system.lock();
    NAIL_ASSERT(render_system_ref != nullptr);
    _frame_buffer = render_system_ref->createFrameBuffer(width, height);

    setViewPort(ViewPort{.x=0, .y=0, .width=width, .height=height});
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

void testDemo1() {
    
    float vertices[] = {
         0.5f,  0.5f, 0.0f,  // top right
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left 
    };
    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };
    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glDrawArrays(GL_TRIANGLES, 0, 3);

}

void OpenglRenderTarget::enableDepthTest(bool enable) {
    _enable_depth_test = enable;
}

GLuint OpenglRenderTarget::getRenderTargetTbo() {
    return _frame_buffer->getTbo();
}

void OpenglRenderTarget::render(std::vector<ref<IRenderable>> renderables, std::list<ref<Light>> lights, mat4 view_matrix, vec3 view_pos) {
    auto render_system = _render_system.lock();
    NAIL_ASSERT(render_system != nullptr);
    ref<OpenglShaderPhongLight> phong_light_shader = render_system->getPhongLightShader();
    phong_light_shader->setSceneLights(lights);

    _frame_buffer->apply();
    glViewport(0, 0, _width, _height);

    glClearColor(_clear_color.r, _clear_color.b, _clear_color.g, _clear_color.a);
    if (_enable_depth_test) {
        render_system->enableDepthTest();
    }
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for(auto renderable_obj : renderables) {
        MeshList meshs = renderable_obj->getMeshs();
        mat4 model_matrix = renderable_obj->getModelMatrix();
        for(auto mesh : meshs) {
            ref<Material> material =  mesh->getMaterial();
            std::vector<ref<Pass>> passes = material->getPasses();

            ref<VertexData> vertex_data = mesh->getVertexData();
            ref<VertexDataDescription> vertex_desc = vertex_data->getVertexDataDescription();

            auto vertex_buffer = std::dynamic_pointer_cast<OpenglVertexBuffer>(vertex_data->getRenderVertexBuffer());
            NAIL_ASSERT(vertex_buffer != nullptr);

            phong_light_shader->setup(passes[0], model_matrix, view_matrix, _projection_matrix, view_pos);

            render_system->rasterize(vertex_buffer, vertex_desc, phong_light_shader);
        }
    }
    _frame_buffer->unapply();
    //render_system->swapActiveBuffers();
    //glfwPollEvents();
}