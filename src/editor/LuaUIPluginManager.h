#pragma once
#include "Editor.h"
#include "LuaUIPlugin.h"
#include <map>

namespace nail::editor {
    class LuaUIPluginManager: public Editor {
    public:
        using MenuPath = std::string;
    private:
        std::string plugin_dir = "./LuaUI";
        std::map<MenuPath, LuaUIPlugin> lua_ui_plugins;
    };
}