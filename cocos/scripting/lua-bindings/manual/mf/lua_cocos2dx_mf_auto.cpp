#include "lua_cocos2dx_ui_mf_auto.hpp"

int register_all_cocos2dx_mf(lua_State* L)
{
    if (nullptr == L)
        return 0;
    
    register_all_cocos2dx_ui_mf(L);
    
    return 0;
}

