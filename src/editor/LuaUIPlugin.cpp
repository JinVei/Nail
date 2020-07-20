#include "LuaUIPlugin.h"
#include "common/assert.h"

using namespace nail::editor;

LuaViewWrapper::LuaViewWrapper(ref<imgui::View> v): View(0){
    view_ = v;
}

void LuaViewWrapper::setBeforeDraw(LuaFunc func) {
    before_draw_ = func;
}

void LuaViewWrapper::setAfterDraw(LuaFunc func) {
    after_draw_ = func;
}

void LuaViewWrapper::draw() {
    if (before_draw_ != nullptr) {
        before_draw_();
    }

    if (view_ != nullptr) {
        view_->draw();
    }

    if (after_draw_ != nullptr) {
        after_draw_();
    }
}

LuaUIPlugin::LuaUIPlugin(std::string plugin_path) {
    JV_ASSERT(plugin_path != "");

    plugin_path_ = plugin_path;
}