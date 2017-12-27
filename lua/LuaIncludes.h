#ifndef LUA_CUSTOM_INCLUDES_H
#define LUA_CUSTOM_INCLUDES_H

#include <lua5.2/lua.hpp>
#include <string>

template <typename T>
void AddLuaFunction(lua_State* luastate, T fun, const std::string& name)
{
    lua_pushcfunction(luastate, fun);
    lua_setglobal(luastate, name.c_str());
}

void CallLuaScript(lua_State* luastate, const std::string& name, void (*errorHandler)(const std::string&))
{
    if(!luaL_loadfile(luastate, name.c_str()))
    {
        lua_pcall(luastate, 0,0,0);
    }
    else
    {
        errorHandler(std::string("Error Loading: ") + name);
    }
    return;
}

#endif
