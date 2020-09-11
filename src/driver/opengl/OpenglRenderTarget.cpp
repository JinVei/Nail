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

    glBindBuffer(GL_ARRAY_BUFFER, 0); 

}

void OpenglRenderTarget::render(std::vector<ref<IRenderable>> renderables, std::list<ref<Light>>, mat4 view_matrix, vec3 view_pos) {
    glViewport(_view_port.x, _view_port.x, _view_port.width, _view_port.height);
    auto render_system = _render_system.lock();
    NAIL_ASSERT(render_system != nullptr);
    ref<OpenglShaderPhongLight> phong_light_shader = render_system->getPhongLightShader();

    //TODO
    //_frame_buffer->apply();
    glViewport(0, 0, 800, 600);
    glClearColor(0.1f, 0.1f, 0.1f, 0.1f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // test
    OpenglShader shader_demo;
    shader_demo.compile(String("./shader/vertex_demo.glsl"), String("./shader/fragment_demo.glsl"));
    // testDemo1();
    // shader_demo.apply();
    // glDrawArrays(GL_TRIANGLES, 0, 3);
    // //

    for(auto renderable_obj : renderables) {
        MeshList meshs = renderable_obj->getMeshs();
        for(auto mesh : meshs) {
            ref<Material> material =  mesh->getMaterial();
            ref<VertexData> vertex_data = mesh->getVertexData();
            ref<VertexDataDescription> desc = vertex_data->getVertexDataDescription();

            auto vertex_buffer = std::dynamic_pointer_cast<OpenglVertexBuffer>(vertex_data->getRenderVertexBuffer());
            NAIL_ASSERT(vertex_buffer != nullptr);
            vertex_buffer->apply();
            std::vector<ref<Pass>> passes = material->getPasses();

            phong_light_shader->setup(passes[0], view_matrix, renderable_obj->getModelMatrix(), _projection_matrix, view_pos);

            //phong_light_shader->apply();
            //test
            testDemo1();
            shader_demo.apply();
            //

            render_system->drawTriangle(desc->_vertex_offset, desc->_vertex_num);
        }
    }
    glfwPollEvents();
    render_system->swapActiveBuffers();
}