#include "lua_cocos2dx_ui_auto.hpp"
#include "CocosGUI.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"


TOLUA_API int register_all_cocos2dx_ui_mf(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"ccmf",0);
	tolua_beginmodule(tolua_S,"ccmf");


	tolua_endmodule(tolua_S);
	return 1;
}

