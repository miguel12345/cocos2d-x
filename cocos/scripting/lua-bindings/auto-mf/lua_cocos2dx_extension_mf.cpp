#include "lua_cocos2dx_extension_mf.hpp"
#include "Downloader.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"


TOLUA_API int register_all_cocos2dx_extension_mf(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"ccmf",0);
	tolua_beginmodule(tolua_S,"ccmf");


	tolua_endmodule(tolua_S);
	return 1;
}

