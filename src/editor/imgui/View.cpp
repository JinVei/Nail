#include "View.h"
#include "common/assert.h"
#include "imgui/imgui.h"

#define ASSERT JV_ASSERT

using namespace nail::editor::imgui;
using namespace nail::editor;

nail::ref<ImguiGraphicAPIHelper> View::s_gapi_helper = nullptr;

View::View(int id=0) {
    id_ = id;
}

void View::draw() {
    beginDraw();
    for (auto& v : childs_){
        v->draw();
    }
    endDraw();
}

View* View::addChild(View* v) {
    childs_.push_back(v);
    return this;
}

void View::delChild(long id) {
    for (auto it = childs_.begin(); it != childs_.end(); ){
       if((*it)->id_ == id) {
           it = childs_.erase(it);
       } else {
           it++;
       }
    }
}

void View::beginDraw() {
    ASSERT(s_gapi_helper !=nullptr);
    s_gapi_helper->beginFrame();
    ImGui::NewFrame();
    ImGui::Begin(" ");
}

void View::endDraw() {
    ASSERT(s_gapi_helper !=nullptr);
    ImGui::End();
    ImGui::Render();
    s_gapi_helper->endFrame();
}

void View::setGraphicAPIHelper(ref<ImguiGraphicAPIHelper> gapi_helper) {
    s_gapi_helper = gapi_helper;
}