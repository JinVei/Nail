#include "LuaUIRegister.h"
#include "lua/lualib.h"
#include "imgui/imgui.h"
#include "common/plog.h"

static int TextUI(lua_State *L) {
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


static const struct luaL_Reg lua_ui_lib[] = {
    {"Text", TextUI},
  {NULL, NULL},
};

void registerLuaUI(lua_State* luavm) {
    lua_newtable(luavm);
    luaL_setfuncs(luavm, lua_ui_lib, 0);
    lua_setglobal(luavm, "imgui");
    return;
}