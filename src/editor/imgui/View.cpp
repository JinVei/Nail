#include "View.h"
#include "common/assert.h"
#include "imgui/imgui.h"
#include <string>
#define ASSERT JV_ASSERT

using namespace nail::editor::imgui;
using namespace nail::editor;

View::View(int id=0) {
    id_ = id;
}
void View::drawChilds() {
        for (auto& v : childs_){
        v->draw();
    }
}
void View::draw() {
    ImGui::Begin(" ");
    drawChilds();
    ImGui::End();
}

View* View::addChild(ref<View> v) {
    childs_.push_back(v);
    return this;
}

View* View::delChild(long id) {
    for (auto it = childs_.begin(); it != childs_.end(); ){
       if((*it)->id_ == id) {
           it = childs_.erase(it);
       } else {
           it++;
       }
    }
    return this;
}

// void View::beginWindow(std::string title) {
//     ImGui::Begin(title.c_str());
// }

// void View::endWindow() {
//     ImGui::End();
// }
