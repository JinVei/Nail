#include "LuaUIPlugin.h"
#include "LuaUIRegister.h"
#include "common/assert.h"
#include "common/plog.h"
#include "imgui/imgui.h"
#include "lua/lua.hpp"

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

LuaUIPlugin::~LuaUIPlugin() {
    if(lua_vm_ != nullptr) {
        lua_close(lua_vm_);
    }
}

void LuaUIPlugin::drawUI() {
    JV_ASSERT(lua_vm_ != nullptr);
    auto vm = lua_vm_;

    switch(mode_) {
    case  LuaUIDrawMode::IMGUI:
        if (lua_getglobal(vm, callback_func_name_.on_draw.c_str()) != LUA_TFUNCTION) {
            Plog("[error] Cant find the function of 'onDraw'");
            break;
        }
        if (lua_pcall(vm, 0, 0, 0) != 0) {
            Plog("[error] get error in lua funcall of 'onDraw': %s", lua_tostring(vm, -1));
            break;
        }
        break;
    default:
        Plog("[error] Unkown mode:%d", mode_);
        break;
    }
}

int LuaUIPlugin::load() {
    if (lua_vm_ != nullptr) {
        lua_close(lua_vm_);
    }

    lua_vm_ = luaL_newstate();
    JV_ASSERT(lua_vm_ != nullptr);

    luaL_openlibs(lua_vm_);

    registerLuaUI(lua_vm_);

    if (luaL_dofile(lua_vm_, plugin_path_.c_str()) != 0) {
        Plog("[error] Get error in luaL_dofile:%s", lua_tostring(lua_vm_,-1));
        return -1;
    }
    return 0;
}