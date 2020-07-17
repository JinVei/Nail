#pragma once
#include "Editor.h"
namespace nail {
    class GLFWGraphicAPIHelper;

    class ImguiEditor: public Editor {
        bool is_init_ = false;
        bool is_destroy_ = false;
        GLFWGraphicAPIHelper* gapi_helper_ = nullptr;
    public:
        virtual int initialize(GraphicAPIHelper* gapi_helper) override;
        virtual int destroy() override;
        virtual void drawUI() override;
        virtual ~ImguiEditor() override;
        void startFrame();
        void finishFrame();
    };
}