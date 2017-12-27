
#include <lua5.2/lua.hpp>
#include <iostream>

int write(lua_State* L)
{
    const char* str = lua_tostring(L, 1);
    std::cout << "C++: " << str << std::endl;
}

int main(int argc, char** argv)
{
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    lua_pushcfunction(L, write);
    lua_setglobal(L, "c_write");
    std::cout << argv[1] << "\n";
    if(!luaL_loadfile(L, argv[1])) {
        lua_pcall(L, 0,0,0);
    } else {
        std::cout << "error loading file\n";
    }
    return 0;
}
