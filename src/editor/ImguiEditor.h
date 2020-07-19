#pragma once
#include "Editor.h"
#include "ImguiGraphicAPIHelper.h"

namespace nail {
    class ImguiEditor: public Editor {
        bool is_init_ = false;
        bool is_destroy_ = false;
        ImguiGraphicAPIHelper* gapi_helper_ = nullptr;
    public:
        ImguiEditor(ImguiGraphicAPIHelper* gapi_helper);
        virtual ~ImguiEditor() override;
        virtual int initialize() override;
        virtual int destroy() override;
        virtual void drawUI() override;
        void startFrame();
        void endFrame();
    };
}