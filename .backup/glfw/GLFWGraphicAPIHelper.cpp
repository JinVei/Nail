#include "GLFWHeader.h"

#include "GLFWGraphicAPIHelper.h"
//#include "imgui/imgui.h"

#include <stdio.h>


// [Win32] Our example includes a copy of glfw3.lib pre-compiled with VS2010 to maximize ease of testing and compatibility with old VS compilers.
// To link with VS2010-era libraries, VS2015+ requires linking with legacy_stdio_definitions.lib, which we do using this pragma.
// Your own project should not be affected, as you are likely to link with a newer binary of GLFW that is adequate for your version of Visual Studio.
#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

using namespace nail;
using namespace nail::renderer::glfw;

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

int GLFWGraphicAPIHelper::initGraphicApi() {
    if(is_init_) {
        return 0;
    }
    is_init_ = true;
    // Setup window
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

    // Decide GL+GLSL versions
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // Create window with graphics context
    // GLFWwindow* window = glfwCreateWindow(1280, 720, "Dear ImGui GLFW+OpenGL3 example", NULL, NULL);
    // if (window == NULL)
    //     return 1;
    // glfwMakeContextCurrent(window);
    // glfwSwapInterval(1); // Enable vsync
    this->createWindow("",1280, 720);
    
    // Initialize OpenGL loader
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        fprintf(stderr,"Failed to initialize GLAD\n");
        return 1;
    }
    return 0;
}

int GLFWGraphicAPIHelper::createWindow(std::string window_name="", int w=1280, int h=720) {
    GLFWwindow* window = glfwCreateWindow(w, h, window_name.c_str(), NULL, NULL);
    if (window == NULL)
        return 1;
    auto existed_window = windowsVec_.find(window_name);
    if (existed_window != windowsVec_.end()){
        return 2;
    }

    windowsVec_[window_name] = ref<GLFWwindowWrapper>(new GLFWwindowWrapper(window, w, h));
    if (currentWindow_ == nullptr) {
        currentWindow_ = windowsVec_[window_name];
        glfwMakeContextCurrent(currentWindow_->getWindow());
        glfwSwapInterval(1); // Enable vsync
    }
    return 0;
}

int GLFWGraphicAPIHelper::useWindow(std::string window_name){
    auto existed_window = windowsVec_.find(window_name);
    if (existed_window == windowsVec_.end()){
        return 2;
    }
    currentWindow_ = existed_window->second;
    glfwMakeContextCurrent(currentWindow_->getWindow());
    return 0;
}

GLFWGraphicAPIHelper::~GLFWGraphicAPIHelper() {
}

ref<GLFWwindowWrapper> GLFWGraphicAPIHelper::getCurrentGLFWwindow() {
    return currentWindow_;
}

char const* GLFWGraphicAPIHelper::getGLSLVersion() {
    return glsl_version_;
}

bool GLFWGraphicAPIHelper::isCurrtentWindowClosed() {
    return currentWindow_->isClosed();
}

int GLFWGraphicAPIHelper::destroy() {
    if (!is_init_) {
        return 1;
    }
    
    if(is_destroy_) {
        return 0;
    }
    is_destroy_ = true; 
    if (currentWindow_ != nullptr) {
        glfwDestroyWindow(currentWindow_->getWindow());
    }
    glfwTerminate();
    return 0;
}

int GLFWGraphicAPIHelper::Update() {
    glfwSwapBuffers(currentWindow_->getWindow());
    return 0;
}