#include "LuaUIPlugin.h"
#include "common/assert.h"
#include "common/plog.h"

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

void LuaUIPlugin::drawUI() {
    JV_ASSERT(lua_vm_ != nullptr);
    auto vm = lua_vm_.get();

    switch(mode_) {
    case  LuaUIDrawMode::IMGUI:
        lua_getglobal(vm, "onDraw");
        if (lua_pcall(vm, 0, 0, 0) != 0) {
            Plog("[error] get error in lua function of 'onDraw': %s", lua_tostring(vm, -1));
        }
        break;
    default:
        break;
    }
}