#pragma once
#include "GraphicAPIHelper.h"
#include "Window.h"
#include "GLFWwindowWrapper.h"
#include "common/ref.h"
#include <map>
namespace nail {
    class GLFWGraphicAPIHelper: public GraphicAPIHelper {
        ref<GLFWwindowWrapper> currentWindow_ = nullptr;
        std::map<std::string, ref<GLFWwindowWrapper>> windowsVec_;
        char* glsl_version_ = nullptr;
        bool is_init_ = false;
        bool is_destroy_ = false;
    public:
        ~GLFWGraphicAPIHelper();
        //virtual int setWindowsEventHandler(std::string window_name, std::function<void()>);
        virtual int initGraphicApi() override;
        virtual int createWindow(std::string window_name, int w, int h) override;
        virtual int useWindow(std::string window_name) override;
        ref<GLFWwindowWrapper> getCurrentGLFWwindow();
        char* getGLSLVersion();
        virtual bool isCurrtentWindowClosed() override;
        virtual int destroy() override;
    };
}