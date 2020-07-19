#include "GLFWwindowWrapper.h"

namespace nail {
    GLFWwindowWrapper::GLFWwindowWrapper(GLFWwindow* window, int w, int h) {
        window_ = window;
        wide_ = w;
        high_ = h;
    }

    GLFWwindowWrapper::~GLFWwindowWrapper(){
        glfwDestroyWindow(window_);
    }

    GLFWwindow* GLFWwindowWrapper::getWindow() {
        return window_;
    }

    std::string GLFWwindowWrapper::getName() {
        return name_;
    }

    int GLFWwindowWrapper::setTitle(std::string title){
        title_ = title;
        glfwSetWindowTitle(window_, title_.c_str());
        return 0;
    }

    int GLFWwindowWrapper::setSize(int wide, int high) {
        wide_ = wide;
        high_ = high;
        return 0;
    }

    std::pair<int,int> GLFWwindowWrapper::getSize() {
        return std::pair<int, int>(wide_, high_);
    }

    bool GLFWwindowWrapper::isClosed() {
        return glfwWindowShouldClose(window_);
    }

    std::string GLFWwindowWrapper::getTitle() {
        return title_;
    }
}