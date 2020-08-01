#pragma once
#include <list>
#include <string>
#include "common/ref.h"

namespace nail::editor::imgui {
    class View {
        std::list<ref<View>> childs_;
        long id_ = 0;
    protected:
        // static void beginWindow(std::string title);
        // static void endWindow();
        void drawChilds();
    public:
        View(int id);
        virtual ~View() = default;
        virtual void draw();
        virtual View* add(ref<View>);
        virtual View* del(long id);
    };
}