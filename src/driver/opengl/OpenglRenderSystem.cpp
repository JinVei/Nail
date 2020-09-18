#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include "OpenglRenderSystem.h"
#include "common/assert.h"
#include "OpenglVertexBufferFactory.h"

#include <iostream>

using namespace nail;

// static void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
//     glViewport(0, 0, width, height);
// }
OpenglRenderSystem::OpenglRenderSystem() {
    _phong_light_shader = ref_create<OpenglShaderPhongLight>();
    _screen_shader = ref_create<OpenglShaderScreen>();
}

wref<OpenglRenderSystem> OpenglRenderSystem::self() {
    return std::dynamic_pointer_cast<OpenglRenderSystem>(_self.lock());
}

void OpenglRenderSystem::_setupScreenVertexData(){

    _screen_vertex_data = ref_create<VertexData>();

    std::vector<float> rt_vertex_data = {
        // vertex coords   textture coords
        -1.0f, -1.0f, 0.0f,   0.0f, 0.0f, // left down
        -1.0f, 1.0f, 0.0f,   0.0f, 1.0f, // left up
        1.0f, -1.0f, 0.0f,   1.0f, 0.0f, // right down

        -1.0f, 1.0f, 0.0f,   0.0f, 1.0f,
        1.0f, -1.0f, 0.0f,   1.0f, 0.0f,
        1.0f, 1.0f, 0.0f,   1.0f, 1.0f,
    };

    auto vertex_descr = ref_create<VertexDataDescription>();
    vertex_descr->_vertex_num = 6;
    vertex_descr->_vertex_size = 3;
    vertex_descr->_vertex_offset = 0;
    vertex_descr->_texture_coord_size = 2;
    vertex_descr->_texture_coord_offset = 3 * sizeof(float);
    vertex_descr->_stride = 5 * sizeof(float);


    auto factory = getRenderVertexBufferFactory();
    auto vertex_buffer_factory = ref_cast<OpenglVertexBufferFactory>(factory);
    NAIL_ASSERT(vertex_buffer_factory != nullptr);

    auto vb = vertex_buffer_factory->createVertexBuffer(
                                        *vertex_descr, 
                                        rt_vertex_data, 
                                        _screen_vertex_data->getIndexData()
                                    );
    auto vertex_buffer = ref_cast<OpenglVertexBuffer>(vb);
    NAIL_ASSERT(vertex_buffer != nullptr);

    _screen_vertex_data->setData(std::move(rt_vertex_data));
    _screen_vertex_data->setVertexDataDescription(vertex_descr);
    _screen_vertex_data->setRenderVertexBuffer(vertex_buffer);
}

bool OpenglRenderSystem::setup() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    unsigned int screenWidth = 800;
    unsigned int screenHeight = 600;
    _window = glfwCreateWindow(screenWidth, screenHeight, "Nail", NULL, NULL);

    NAIL_ASSERT(_window != NULL);

    if (_window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(_window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return false;
    }

    glViewport(0, 0, 800, 600);

    NAIL_ASSERT(_phong_light_shader->compile(phong_light_vertex_shader_path, phong_light_fragment_shader_path));
    NAIL_ASSERT(_screen_shader->compile(screen_vertex_shader_path, screen_frag_shader_path));
    // glfwSetFramebufferSizeCallback(_window, framebufferSizeCallback);
    //glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    _setupScreenVertexData();
    return true;
}

void OpenglRenderSystem::enableDepthTest() {
    glEnable(GL_DEPTH_TEST);
}

void OpenglRenderSystem::swapActiveBuffers() {
    glfwSwapBuffers(_window);
}

ref<RenderTarget> OpenglRenderSystem::createRenderTarget(float width, float height) {
    GUID id = GuidCreatetor::create();
    auto render_target = ref<OpenglRenderTarget>(new OpenglRenderTarget(self(), width, height));
    _render_targets.insert(std::pair(id, render_target));

    return render_target;
}

ref<OpenglFrameBuffer> OpenglRenderSystem::createFrameBuffer(float width, float height) {
    return ref<OpenglFrameBuffer>(new OpenglFrameBuffer(width,height));
}

ref<OpenglShaderPhongLight> OpenglRenderSystem::getPhongLightShader() {
    return _phong_light_shader;
}

ref<OpenglShaderScreen> OpenglRenderSystem::getScreenShader() {
    return _screen_shader;
}

bool OpenglRenderSystem::windowShouldClose() {
    return glfwWindowShouldClose(_window);
}

void OpenglRenderSystem::rasterize(
    ref<OpenglVertexBuffer> vertex_buffer,
    ref<VertexDataDescription> desc,
    ref<OpenglShader> shader)
{
    NAIL_ASSERT(vertex_buffer != nullptr && desc != nullptr && shader != nullptr);
    vertex_buffer->apply();
    shader->apply();

    if(vertex_buffer->hasIndexBuffer()) {
        glDrawElements(GL_TRIANGLES, desc->_vertex_indices_num, GL_UNSIGNED_INT, 0);
    } else {
        glDrawArrays(GL_TRIANGLES, 0, desc->_vertex_num);
    }
}

void OpenglRenderSystem::render() {

    auto screen_shader = getScreenShader();
    ref<VertexDataDescription> vertex_descr = _screen_vertex_data->getVertexDataDescription();
    auto vb = _screen_vertex_data->getRenderVertexBuffer();
    auto vertex_buffer = ref_cast<OpenglVertexBuffer>(vb);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glDisable(GL_DEPTH_TEST);

    for (auto render_target_pair : _render_targets) {
        auto render_target = render_target_pair.second;
        
        RenderTarget::ViewPort view_port = render_target->getViewPort();
        glViewport(view_port.x, view_port.y, view_port.width, view_port.height);

        GLuint tex_id = render_target->getRenderTargetTbo();
        screen_shader->apply(tex_id);
        rasterize(vertex_buffer, vertex_descr, screen_shader);
    }
    glfwSwapBuffers(_window);
    glfwPollEvents();
}