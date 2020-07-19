#pragma once
#include "editor/ImguiGraphicAPIHelper.h"
#include <list>
#include "common/ref.h"

namespace nail::editor::imgui {
    class View {
        std::list<View*> childs_;
        long id_ = 0;
    protected:
        static ref<ImguiGraphicAPIHelper> gapi_helper;
        virtual void beginDraw();
        virtual void endDraw();
    public:
        View(int id);
        virtual ~View() = default;
        virtual void draw();
        virtual View* addChild(View*);
        virtual void delChild(long id);
    };
}