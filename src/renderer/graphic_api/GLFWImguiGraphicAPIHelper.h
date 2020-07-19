#pragma once
#include "editor/ImguiGraphicAPIHelper.h"

namespace nail {
    class GLFWGraphicAPIHelper;
    class GLFWImguiGraphicAPIHelper: public  ImguiGraphicAPIHelper {
        GLFWGraphicAPIHelper* gapi_helper_;
    public:
        GLFWImguiGraphicAPIHelper(GLFWGraphicAPIHelper*);
        virtual int beginFrame() override;
        virtual int endFrame() override;
        int initialize();
        int destroy();
    };
}