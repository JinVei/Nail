#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include "OpenglRenderSystem.h"
#include "common/assert.h"

#include <iostream>

using namespace nail;

// static void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
//     glViewport(0, 0, width, height);
// }
OpenglRenderSystem::OpenglRenderSystem() {
    _phong_light_shader = ref<OpenglShaderPhongLight>(new OpenglShaderPhongLight());
}

wref<OpenglRenderSystem> OpenglRenderSystem::self() {
    return std::dynamic_pointer_cast<OpenglRenderSystem>(_self.lock());
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

    NAIL_ASSERT(_phong_light_shader->compile(String("./shader/phong_light_vertex.glsl"), String("./shader/phong_light_fragment.glsl")));
    // glfwSetFramebufferSizeCallback(_window, framebufferSizeCallback);
    //glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    return true;
}

void OpenglRenderSystem::enableDeepTest() {
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

void OpenglRenderSystem::drawTriangle(GLint first, GLsizei count) {
    glDrawArrays(GL_TRIANGLES, first, count);
}

bool OpenglRenderSystem::windowShouldClose() {
    return glfwWindowShouldClose(_window);
}