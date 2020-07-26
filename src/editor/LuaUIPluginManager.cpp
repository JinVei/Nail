#include "LuaUIPluginManager.h"

#include <string>
#include <iostream>
#include <boost/filesystem.hpp>
#include <list>
#include <string>

using namespace nail::editor;

namespace fs = boost::filesystem;

std::list<std::string> LuaUIPluginManager::listPluginPath(std::string root_dir) {
    std::list<std::string> plugin_paths;
    std::string lua_prefix = ".lua";
    for (const auto & path : fs::directory_iterator(root_dir)) {
        if (fs::path(path).extension() == lua_prefix) {
            plugin_paths.push_back(path.path().string());
        }
    }
    return plugin_paths;
}

void LuaUIPluginManager::drawUI() {

}

int LuaUIPluginManager::loadPlugins() {
    return 0;
}

int LuaUIPluginManager::initialize() {
    return 0;
}
int LuaUIPluginManager::destroy() {
    return 0;
}