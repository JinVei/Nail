#pragma once
#include "lua/lua.hpp"
#include "imgui/View.h"
#include <functional>

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
    enum class LuaUIDrawMode {
        IMGUI,
        ControlUI
    };
    class LuaUIPlugin {
    public:
        struct CallbackFuncName {
            std::string on_draw = "onDraw";
        };
    private:
        ref<LuaViewWrapper> lua_ui_ = nullptr;
        lua_State* lua_vm_ = nullptr;
        std::string plugin_path_;
        LuaUIDrawMode mode_ = LuaUIDrawMode::IMGUI;
        CallbackFuncName callback_func_name_;

    public:
        LuaUIPlugin(std::string plugin_path);
        ~LuaUIPlugin();
        void drawUI();
        int loadPlugin();
    };
}