
lua_simple: lua/LuaSimpleMain.cpp
	g++ -o LuaSimple.out lua/LuaSimpleMain.cpp -llua5.2 -ldl -I/usr/include

lua_class: lua/LuaClassMain.cpp lua/LuaScript.cpp lua/LuaScript.hpp
	g++ -o LuaClass.out lua/LuaClassMain.cpp lua/LuaScript.cpp -llua5.2 -ldl -I/usr/include

lua_functions: lua/LuaFunctionsMain.cpp
	g++ -o LuaFunctions.out lua/LuaFunctionsMain.cpp -llua5.2 -ldl -I/usr/include


lua_helpers: lua/LuaHelperFunctionsMain.cpp lua/LuaIncludes.h
	g++ -o LuaHelperFunctions.out lua/LuaHelperFunctionsMain.cpp -llua5.2 -ldl -I/usr/include
