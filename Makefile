
# Lua ToDo: do class integration, try the following methods.
# 1. Add the class itself to lua
# 2. Expose static functions and pass to lua an object id. Lua calls these funcitons with the object id
# 3. Try to use meta programming to generate the bindings
# 4. Try to make a class to act as a builder of lua objects

lua_simple: lua/LuaSimpleMain.cpp
	g++ -o LuaSimple.out lua/LuaSimpleMain.cpp -llua5.2 -ldl -I/usr/include

lua_config: lua/LuaConfigMain.cpp lua/LuaConfig.cpp lua/LuaConfig.hpp
	g++ -o LuaConfig.out lua/LuaConfigMain.cpp lua/LuaConfig.cpp -llua5.2 -ldl -I/usr/include

lua_functions: lua/LuaFunctionsMain.cpp
	g++ -o LuaFunctions.out lua/LuaFunctionsMain.cpp -llua5.2 -ldl -I/usr/include

lua_helpers: lua/LuaHelperFunctionsMain.cpp lua/LuaIncludes.h
	g++ -o LuaHelperFunctions.out lua/LuaHelperFunctionsMain.cpp -llua5.2 -ldl -I/usr/include


# Python to do
# 1. Call python scripts using the interpreter
# 2. Try to create a PythonConfig class that can read python formatted data
# 3. Try to expose c functions to python
# 4. Expose a C++ class in python
# 5. Try Cython

python_string: python/RunStringMain.cpp
	g++ -o PythonRunString.out python/RunStringMain.cpp -I/usr/include/python2.7 -L/usr/lib/python2.2/config/ -lpython2.7

clean:
	rm *.out
