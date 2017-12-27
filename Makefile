
lua_simple: lua/LuaSimpleMain.cpp
	g++ -o LuaSimple.out lua/LuaSimpleMain.cpp -llua5.2 -ldl -I/usr/include

lua_config: lua/LuaConfigMain.cpp lua/LuaConfig.cpp lua/LuaConfig.hpp
	g++ -o LuaConfig.out lua/LuaConfigMain.cpp lua/LuaConfig.cpp -llua5.2 -ldl -I/usr/include

lua_functions: lua/LuaFunctionsMain.cpp
	g++ -o LuaFunctions.out lua/LuaFunctionsMain.cpp -llua5.2 -ldl -I/usr/include


lua_helpers: lua/LuaHelperFunctionsMain.cpp lua/LuaIncludes.h
	g++ -o LuaHelperFunctions.out lua/LuaHelperFunctionsMain.cpp -llua5.2 -ldl -I/usr/include

clean:
	rm *.out
