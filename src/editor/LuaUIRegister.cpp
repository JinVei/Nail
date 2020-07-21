#include "LuaUIRegister.h"
#include "lua/lualib.h"
#include "imgui/imgui.h"
#include "common/plog.h"
#include "common/assert.h"
#include <string>

static int TextUI(lua_State *L) {
    JV_ASSERT( L != nullptr);

    int top = lua_gettop(L);
    if (top == 0) {
        Plog("[error] top is equal to 0");
        return 0;
    }

    int arg_type = lua_type(L, 1);
    if (arg_type != LUA_TSTRING) {
        Plog("[error] TextUI parameter is not match the type of string");
        return 0;
    }
    const char* text = lua_tostring(L, 1);

    ImGui::Text("%s", text);
    return 0;
}

static int BeginUI(lua_State *L) {
    JV_ASSERT( L != nullptr);
    std::string title = " ";
    int top = lua_gettop(L);
    if (0 < top && lua_type(L, 1) == LUA_TSTRING) {
        title = lua_tostring(L, 1);
    }
    ImGui::Begin(title.c_str());
    return 0;
}

static int EndUI(lua_State *L) {
    JV_ASSERT( L != nullptr);
    ImGui::End();
    return 0;
}

static const struct luaL_Reg lua_ui_lib[] = {
    {"Begin", BeginUI},
    {"End", EndUI},
    {"Text", TextUI},
    {NULL, NULL},
};

void registerLuaUI(lua_State* luavm) {
    lua_newtable(luavm);
    luaL_setfuncs(luavm, lua_ui_lib, 0);
    lua_setglobal(luavm, "imgui");
    return;
}