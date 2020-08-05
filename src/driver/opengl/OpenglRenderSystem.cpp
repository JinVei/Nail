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