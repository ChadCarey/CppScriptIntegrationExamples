
lua_simple: lua/LuaSimpleMain.cpp
	g++ -o LuaSimple.out lua/LuaSimpleMain.cpp -llua5.2 -ldl -I/usr/include

lua_class: lua/LuaClassMain.cpp lua/LuaScript.cpp lua/LuaScript.hpp
	g++ -o LuaClass.out lua/LuaClassMain.cpp lua/LuaScript.cpp -llua5.2 -ldl -I/usr/include
