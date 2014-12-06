#include "lua_cocos2dx_experimental_auto.hpp"
#include "lua_cocos2dx_experimental_manual.hpp"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"
#include "CCLuaValue.h"
#include "CCLuaEngine.h"
#include "UIWebView.h"

static int lua_cocos2dx_experimental_TMXLayer_getTileGIDAt(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::experimental::TMXLayer* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccexp.TMXLayer",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::experimental::TMXLayer*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_experimental_TMXLayer_getTileGIDAt'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        cocos2d::Vec2 arg0;
        
        ok &= luaval_to_vec2(tolua_S, 2, &arg0, "ccexp.TMXLayer:getTileGIDAt");
        if(!ok)
            return 0;
        int ret = cobj->getTileGIDAt(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        tolua_pushnumber(tolua_S,(lua_Number)0);
        return 2;
    }
    if (argc == 2)
    {
        cocos2d::Vec2 arg0;
        int arg1 = 0;
        
        ok &= luaval_to_vec2(tolua_S, 2, &arg0, "ccexp.TMXLayer:getTileGIDAt");
        ok &= luaval_to_int32(tolua_S, 3, &arg1, "ccexp.TMXLayer:getTileGIDAt");
        
        if(!ok)
            return 0;
        
        unsigned int ret = cobj->getTileGIDAt(arg0, (cocos2d::TMXTileFlags*)&arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        tolua_pushnumber(tolua_S,(lua_Number)arg1);
        return 2;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "ccexp.TMXLayer:getTileGIDAt",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_experimental_TMXLayer_getTileGIDAt'.",&tolua_err);
#endif
    
    return 0;
}

static void extendExperimentalTMXLayer(lua_State* tolua_S)
{
    lua_pushstring(tolua_S, "ccexp.TMXLayer");
    lua_rawget(tolua_S, LUA_REGISTRYINDEX);
    if (lua_istable(tolua_S,-1))
    {
        tolua_function(tolua_S, "getTileGIDAt", lua_cocos2dx_experimental_TMXLayer_getTileGIDAt);
    }
    lua_pop(tolua_S, 1);
}

int lua_cocos2dx_experimental_WebView_setOnJSCallback(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::experimental::ui::WebView* cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccexp.WebView",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::experimental::ui::WebView*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_experimental_WebView_setOnJSCallback'", nullptr);
        return 0;
    }
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err))
    {
        goto tolua_lerror;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        
        LUA_FUNCTION handler = (  toluafix_ref_function(tolua_S,2,0));
        
        cobj->setOnJSCallback([=](cocos2d::experimental::ui::WebView * wv, const std::basic_string<char> & url){
            
            LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
            
            stack->pushString(url.c_str());
            
            stack->executeFunctionByHandler(handler, 1);
            stack->clean();
            
        });
        
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "ccexp.WebView:setOnJSCallback",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_experimental_WebView_setOnJSCallback'.",&tolua_err);
#endif
    
    return 0;
}

static void extendWebview(lua_State* tolua_S)
{
    lua_pushstring(tolua_S, "ccexp.WebView");
    lua_rawget(tolua_S, LUA_REGISTRYINDEX);
    if (lua_istable(tolua_S,-1))
    {
        tolua_function(tolua_S, "setOnJSCallback",lua_cocos2dx_experimental_WebView_setOnJSCallback);
    }
    lua_pop(tolua_S, 1);
}

int register_all_cocos2dx_experimental_manual(lua_State* L)
{
    if (nullptr == L)
        return 0;
    
    extendExperimentalTMXLayer(L);
    extendWebview(L);
    
    return 0;
}

int register_experimental_moudle(lua_State* L) {
    lua_getglobal(L, "_G");
    if (lua_istable(L,-1))//stack:...,_G,
    {
        register_all_cocos2dx_experimental(L);
        register_all_cocos2dx_experimental_manual(L);
    }
    lua_pop(L, 1);
    
    return 1;
}

