
#include "LuaIncludes.h"
#include <iostream>

int write(lua_State* L)
{
    const char* str = lua_tostring(L, 1);
    std::cout << "C++: " << str << std::endl;
}

int LuaError(std::string message)
{
    std::cout << message << "\n";
}

int main(int argc, char** argv)
{
    lua_State* L = luaL_newstate();
    luaL_openlibs(L); // load default libraries

    AddLuaFunction(L, write, "c_write");
    CallLuaScript(L, argv[1], LuaError);

    std::cout << argv[1] << "\n";

    return 0;
}
