#include "LuaUIRegister.h"
#include "lua/lualib.h"
#include "imgui/imgui.h"
#include "common/plog.h"
#include "common/assert.h"
#include <string>


static const char* getLuaFuncStringArg(lua_State *L, int n) {
    int top = lua_gettop(L);
    if (top == 0) {
        Plog("[error] top is equal to 0");
        return nullptr;
    }

    int arg_type = lua_type(L, n);
    if (arg_type != LUA_TSTRING) {
        Plog("[error] parameter is not match the type of string");
        return nullptr;
    }
    const char* text = lua_tostring(L, n);
    return text;
}

static std::pair<bool, bool> getLuaFuncBooleanArg(lua_State *L, int n) {
    int top = lua_gettop(L);
    bool err = false;
    if (top == 0) {
        Plog("[error] top is equal to 0");
        err = true;
        return std::pair(false, err);
    }

    int arg_type = lua_type(L, n);
    if (arg_type != LUA_TBOOLEAN) {
        Plog("[error] parameter is not match the type of boolean");
        err = true;
        return std::pair(false, err);
    }
    bool b = lua_toboolean(L, n);
    return std::pair(b, false);
}

static int TextUI(lua_State *L) {
    JV_ASSERT( L != nullptr);

    const char* text = getLuaFuncStringArg(L,1);
    if (text == nullptr) {
        text = "";
    }

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

static int ButtonUI(lua_State *L) {
    JV_ASSERT( L != nullptr);
    const char* button_text = getLuaFuncStringArg(L, 1);
    if (button_text == nullptr) {
        button_text = "";
    }
    bool is_click = ImGui::Button(button_text);
    lua_pushboolean(L, is_click);
    return 1;
}

static int CheckBoxUI(lua_State *L) {
    JV_ASSERT( L != nullptr);
    const char* box_text = getLuaFuncStringArg(L, 1);
    if (box_text == nullptr) {
        box_text = "";
    }

    std::pair<bool,bool> ret = getLuaFuncBooleanArg(L, 2);
    bool is_err = ret.second;
    bool is_select = ret.first;
    if (is_err) {
        Plog("Get error in getLuaFuncBooleanArg(L, 2)");
        return 0;
    }

    ImGui::Checkbox(box_text, &is_select);
    lua_pushboolean(L, is_select);
    return 1;
}

static const struct luaL_Reg lua_ui_lib[] = {
    {"Begin", BeginUI},
    {"End", EndUI},
    {"Text", TextUI},
    {"Button", ButtonUI},
    {"CheckBox", CheckBoxUI},
    {NULL, NULL},
};

void registerLuaUI(lua_State* luavm) {
    lua_newtable(luavm);
    luaL_setfuncs(luavm, lua_ui_lib, 0);
    lua_setglobal(luavm, "imgui");
    return;
}