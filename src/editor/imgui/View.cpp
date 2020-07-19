#include "View.h"
#include "common/assert.h"

#define ASSERT JV_ASSERT

using namespace nail::editor::imgui;
using namespace nail::editor;

nail::ref<ImguiGraphicAPIHelper> View::gapi_helper = nullptr;

View::View(int id=0) {
    id_ = id;
}

void View::draw() {
    for (auto& v : childs_){
        beginDraw();
        endDraw();
    }
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
    ASSERT(gapi_helper !=nullptr);
    gapi_helper->beginFrame();
}

void View::endDraw() {
    ASSERT(gapi_helper !=nullptr);
    gapi_helper->endFrame();
}