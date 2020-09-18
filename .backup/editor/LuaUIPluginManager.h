#pragma once
#include "Editor.h"
#include "LuaUIPlugin.h"
#include <map>
#include <list>
#include <string>

namespace nail::editor {
    class LuaUIPluginManager: public Editor {
    public:
        using MenuPath = std::string;
    private:
        std::string plugin_dir = "./LuaUIPlugins";
        std::map<MenuPath, LuaUIPlugin> lua_ui_plugins;
    public:
        int loadPlugins();
        void drawUI() override;
        std::list<std::string> listPluginPath(std::string root_dir);
        int initialize() override;
        int destroy() override;
    };
}