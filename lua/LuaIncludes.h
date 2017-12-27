#include <lua5.2/lua.hpp>
#include <string>

#define AddLuaFunction(LUASTATE, FUN, NAME) \
    lua_pushcfunction(LUASTATE, FUN); \
    lua_setglobal(LUASTATE, NAME);

#define CallLuaScript(LUASTATE, NAME, ERROR_HANDLER) \
    if(!luaL_loadfile(LUASTATE, NAME)) { \
        lua_pcall(LUASTATE, 0,0,0); \
    } else { \
        ERROR_HANDLER(std::string("Error Loading: ") + std::string(NAME)); \
    }
