#include "GLFWHeader.h"

#include "GLFWGraphicAPIHelper.h"
#include "imgui/imgui.h"

#include <stdio.h>


// [Win32] Our example includes a copy of glfw3.lib pre-compiled with VS2010 to maximize ease of testing and compatibility with old VS compilers.
// To link with VS2010-era libraries, VS2015+ requires linking with legacy_stdio_definitions.lib, which we do using this pragma.
// Your own project should not be affected, as you are likely to link with a newer binary of GLFW that is adequate for your version of Visual Studio.
#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

using namespace nail;

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
#if __APPLE__
    // GL 3.2 + GLSL 150
    glsl_version_ = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#else
    // GL 3.0 + GLSL 130
    glsl_version_ = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
#endif

    // Create window with graphics context
    // GLFWwindow* window = glfwCreateWindow(1280, 720, "Dear ImGui GLFW+OpenGL3 example", NULL, NULL);
    // if (window == NULL)
    //     return 1;
    // glfwMakeContextCurrent(window);
    // glfwSwapInterval(1); // Enable vsync
    this->createWindow("",1280, 720);
    
    // Initialize OpenGL loader
#if __has_include(<GL/gl3w.h>)
    bool err = gl3wInit() != 0;
#elif __has_include(<GL/glew.h>)
    bool err = glewInit() != GLEW_OK;
#elif __has_include(<glad/glad.h>)
    bool err = gladLoadGL() == 0;
#elif __has_include(<glad/gl.h>)
    bool err = gladLoadGL((GLADloadfunc)SDL_GL_GetProcAddress) == 0; // glad2 recommend using the windowing library loader instead of the (optionally) bundled one.
#elif __has_include(<glbinding/Binding.h>)
    bool err = false;
    glbinding::Binding::initialize();
#elif __has_include(<glbinding/glbinding.h>)
    bool err = false;
    glbinding::initialize([](const char* name) { return (glbinding::ProcAddress)SDL_GL_GetProcAddress(name); });
#else
    bool err = false; // If you use IMGUI_IMPL_OPENGL_LOADER_CUSTOM, your loader is likely to requires some form of initialization.
#endif
    if (err)
    {
        fprintf(stderr, "Failed to initialize OpenGL loader!\n");
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

char* GLFWGraphicAPIHelper::getGLSLVersion() {
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