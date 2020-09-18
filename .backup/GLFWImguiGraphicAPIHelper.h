#pragma once
#include "editor/ImguiGraphicAPIHelper.h"
#include "GLFWGraphicAPIHelper.h"
namespace nail::renderer::glfw {
    class GLFWImguiGraphicAPIHelper: public  nail::editor::ImguiGraphicAPIHelper {
       GLFWGraphicAPIHelper* gapi_helper_;
    public:
        GLFWImguiGraphicAPIHelper(GLFWGraphicAPIHelper*);
        virtual int beginFrame() override;
        virtual int endFrame() override;
        int initialize();
        int destroy();
    };
}