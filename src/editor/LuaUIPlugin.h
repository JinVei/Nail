#pragma once
#include "lua/lua.hpp"
#include "imgui/View.h"

namespace nail::editor {
    class LuaViewWrapper: virtual public imgui::View {
    public:
        using LuaFunc = std::function<void()>;
    private:
        ref<imgui::View> view_;
        LuaFunc before_draw_ = nullptr;
        LuaFunc after_draw_ = nullptr;
    public:
        LuaViewWrapper(ref<imgui::View> v);
        void setBeforeDraw(LuaFunc func);
        void setAfterDraw(LuaFunc func);
        void draw() override;
    };

    class LuaUIPlugin {
        ref<LuaViewWrapper> lua_ui_ = nullptr;
        ref<lua_State> lua_vm_ = nullptr;
        std::string plugin_path_;
    public:
        LuaUIPlugin(std::string plugin_path);
    };
}