
#include "LuaIncludes.h"


class Mather:
{
public:
    virtual int doMath(int a, int b) = 0;
};

class Adder: public Mather
{
public:
    virtual int doMath(int a, int b)
    {
        return a+b;
    }
};

class Subtracter: public Mather
{
public:
    virtual int doMath(int a, int b)
    {
        return a-b;
    }
};

// WARNING! GLOBAL VARIABLE. DON'T FORGET TO REMOVE THIS!

int l_doMath(lua_State* lau)
{

}

int l_createAdder(lua_State* lau)
{

}

int l_createSubtracter(lua_State* lau)
{

}

int main()
{
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

    // add the class to lua
    lua_pushcfunction(L, l_doMath);
    lua_setglobal(L, "doMath");

    std::cout << argv[1] << "\n";
    if(!luaL_loadfile(L, argv[1])) {
        lua_pcall(L, 0,0,0);
    } else {
        std::cout << "error loading file\n";
    }

}
