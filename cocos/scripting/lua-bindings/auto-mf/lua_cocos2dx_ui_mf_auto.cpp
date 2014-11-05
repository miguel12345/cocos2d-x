#include "lua_cocos2dx_ui_mf_auto.hpp"
#include "UILazyListView.h"
#include "UIImageViewExtended.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_cocos2dx_ui_mf_LazyListView_setGravity(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::mf::LazyListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"mf.LazyListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::mf::LazyListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_ui_mf_LazyListView_setGravity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::extension::mf::LazyListView::Gravity arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "mf.LazyListView:setGravity");
        if(!ok)
            return 0;
        cobj->setGravity(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "mf.LazyListView:setGravity",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ui_mf_LazyListView_setGravity'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_ui_mf_LazyListView_removeLastItem(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::mf::LazyListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"mf.LazyListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::mf::LazyListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_ui_mf_LazyListView_removeLastItem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeLastItem();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "mf.LazyListView:removeLastItem",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ui_mf_LazyListView_removeLastItem'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_ui_mf_LazyListView_getCurSelectedIndex(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::mf::LazyListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"mf.LazyListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::mf::LazyListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_ui_mf_LazyListView_getCurSelectedIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        ssize_t ret = cobj->getCurSelectedIndex();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "mf.LazyListView:getCurSelectedIndex",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ui_mf_LazyListView_getCurSelectedIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_ui_mf_LazyListView_getItemsMargin(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::mf::LazyListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"mf.LazyListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::mf::LazyListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_ui_mf_LazyListView_getItemsMargin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getItemsMargin();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "mf.LazyListView:getItemsMargin",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ui_mf_LazyListView_getItemsMargin'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_ui_mf_LazyListView_getDataSource(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::mf::LazyListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"mf.LazyListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::mf::LazyListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_ui_mf_LazyListView_getDataSource'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::extension::mf::LazyListViewDataSource* ret = cobj->getDataSource();
        object_to_luaval<cocos2d::extension::mf::LazyListViewDataSource>(tolua_S, "mf.LazyListViewDataSource",(cocos2d::extension::mf::LazyListViewDataSource*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "mf.LazyListView:getDataSource",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ui_mf_LazyListView_getDataSource'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_ui_mf_LazyListView_getIndex(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::mf::LazyListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"mf.LazyListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::mf::LazyListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_ui_mf_LazyListView_getIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::ui::Widget* arg0;

        ok &= luaval_to_object<cocos2d::ui::Widget>(tolua_S, 2, "ccui.Widget",&arg0);
        if(!ok)
            return 0;
        ssize_t ret = cobj->getIndex(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "mf.LazyListView:getIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ui_mf_LazyListView_getIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_ui_mf_LazyListView_pushBackCustomItem(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::mf::LazyListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"mf.LazyListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::mf::LazyListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_ui_mf_LazyListView_pushBackCustomItem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::ui::Widget* arg0;

        ok &= luaval_to_object<cocos2d::ui::Widget>(tolua_S, 2, "ccui.Widget",&arg0);
        if(!ok)
            return 0;
        cobj->pushBackCustomItem(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "mf.LazyListView:pushBackCustomItem",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ui_mf_LazyListView_pushBackCustomItem'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_ui_mf_LazyListView_insertDefaultItem(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::mf::LazyListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"mf.LazyListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::mf::LazyListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_ui_mf_LazyListView_insertDefaultItem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        ssize_t arg0;

        ok &= luaval_to_ssize(tolua_S, 2, &arg0, "mf.LazyListView:insertDefaultItem");
        if(!ok)
            return 0;
        cobj->insertDefaultItem(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "mf.LazyListView:insertDefaultItem",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ui_mf_LazyListView_insertDefaultItem'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_ui_mf_LazyListView_addEventListener(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::mf::LazyListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"mf.LazyListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::mf::LazyListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_ui_mf_LazyListView_addEventListener'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::function<void (cocos2d::Ref *, cocos2d::extension::mf::LazyListView::EventType)> arg0;

        do {
			// Lambda binding for lua is not supported.
			assert(false);
		} while(0)
		;
        if(!ok)
            return 0;
        cobj->addEventListener(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "mf.LazyListView:addEventListener",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ui_mf_LazyListView_addEventListener'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_ui_mf_LazyListView_doLayout(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::mf::LazyListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"mf.LazyListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::mf::LazyListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_ui_mf_LazyListView_doLayout'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->doLayout();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "mf.LazyListView:doLayout",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ui_mf_LazyListView_doLayout'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_ui_mf_LazyListView_removeAllItems(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::mf::LazyListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"mf.LazyListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::mf::LazyListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_ui_mf_LazyListView_removeAllItems'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeAllItems();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "mf.LazyListView:removeAllItems",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ui_mf_LazyListView_removeAllItems'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_ui_mf_LazyListView_getItems(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::mf::LazyListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"mf.LazyListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::mf::LazyListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_ui_mf_LazyListView_getItems'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Vector<cocos2d::ui::Widget *>& ret = cobj->getItems();
        ccvector_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "mf.LazyListView:getItems",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ui_mf_LazyListView_getItems'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_ui_mf_LazyListView_setItemsMargin(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::mf::LazyListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"mf.LazyListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::mf::LazyListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_ui_mf_LazyListView_setItemsMargin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "mf.LazyListView:setItemsMargin");
        if(!ok)
            return 0;
        cobj->setItemsMargin(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "mf.LazyListView:setItemsMargin",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ui_mf_LazyListView_setItemsMargin'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_ui_mf_LazyListView_getItem(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::mf::LazyListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"mf.LazyListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::mf::LazyListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_ui_mf_LazyListView_getItem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        ssize_t arg0;

        ok &= luaval_to_ssize(tolua_S, 2, &arg0, "mf.LazyListView:getItem");
        if(!ok)
            return 0;
        cocos2d::ui::Widget* ret = cobj->getItem(arg0);
        object_to_luaval<cocos2d::ui::Widget>(tolua_S, "ccui.Widget",(cocos2d::ui::Widget*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "mf.LazyListView:getItem",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ui_mf_LazyListView_getItem'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_ui_mf_LazyListView_removeItem(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::mf::LazyListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"mf.LazyListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::mf::LazyListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_ui_mf_LazyListView_removeItem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        ssize_t arg0;

        ok &= luaval_to_ssize(tolua_S, 2, &arg0, "mf.LazyListView:removeItem");
        if(!ok)
            return 0;
        cobj->removeItem(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "mf.LazyListView:removeItem",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ui_mf_LazyListView_removeItem'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_ui_mf_LazyListView_pushBackDefaultItem(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::mf::LazyListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"mf.LazyListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::mf::LazyListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_ui_mf_LazyListView_pushBackDefaultItem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->pushBackDefaultItem();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "mf.LazyListView:pushBackDefaultItem",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ui_mf_LazyListView_pushBackDefaultItem'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_ui_mf_LazyListView_refreshView(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::mf::LazyListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"mf.LazyListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::mf::LazyListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_ui_mf_LazyListView_refreshView'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->refreshView();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "mf.LazyListView:refreshView",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ui_mf_LazyListView_refreshView'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_ui_mf_LazyListView_setDataSource(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::mf::LazyListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"mf.LazyListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::mf::LazyListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_ui_mf_LazyListView_setDataSource'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::extension::mf::LazyListViewDataSource* arg0;

        ok &= luaval_to_object<cocos2d::extension::mf::LazyListViewDataSource>(tolua_S, 2, "mf.LazyListViewDataSource",&arg0);
        if(!ok)
            return 0;
        cobj->setDataSource(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "mf.LazyListView:setDataSource",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ui_mf_LazyListView_setDataSource'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_ui_mf_LazyListView_setItemModel(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::mf::LazyListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"mf.LazyListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::mf::LazyListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_ui_mf_LazyListView_setItemModel'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::ui::Widget* arg0;

        ok &= luaval_to_object<cocos2d::ui::Widget>(tolua_S, 2, "ccui.Widget",&arg0);
        if(!ok)
            return 0;
        cobj->setItemModel(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "mf.LazyListView:setItemModel",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ui_mf_LazyListView_setItemModel'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_ui_mf_LazyListView_requestRefreshView(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::mf::LazyListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"mf.LazyListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::mf::LazyListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_ui_mf_LazyListView_requestRefreshView'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->requestRefreshView();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "mf.LazyListView:requestRefreshView",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ui_mf_LazyListView_requestRefreshView'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_ui_mf_LazyListView_insertCustomItem(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::mf::LazyListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"mf.LazyListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::mf::LazyListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_ui_mf_LazyListView_insertCustomItem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::ui::Widget* arg0;
        ssize_t arg1;

        ok &= luaval_to_object<cocos2d::ui::Widget>(tolua_S, 2, "ccui.Widget",&arg0);

        ok &= luaval_to_ssize(tolua_S, 3, &arg1, "mf.LazyListView:insertCustomItem");
        if(!ok)
            return 0;
        cobj->insertCustomItem(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "mf.LazyListView:insertCustomItem",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ui_mf_LazyListView_insertCustomItem'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_ui_mf_LazyListView_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"mf.LazyListView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocos2d::extension::mf::LazyListView* ret = cocos2d::extension::mf::LazyListView::create();
        object_to_luaval<cocos2d::extension::mf::LazyListView>(tolua_S, "mf.LazyListView",(cocos2d::extension::mf::LazyListView*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "mf.LazyListView:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ui_mf_LazyListView_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_ui_mf_LazyListView_createInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"mf.LazyListView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocos2d::Ref* ret = cocos2d::extension::mf::LazyListView::createInstance();
        object_to_luaval<cocos2d::Ref>(tolua_S, "cc.Ref",(cocos2d::Ref*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "mf.LazyListView:createInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ui_mf_LazyListView_createInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_ui_mf_LazyListView_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::mf::LazyListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::extension::mf::LazyListView();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"mf.LazyListView");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "mf.LazyListView:LazyListView",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ui_mf_LazyListView_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_ui_mf_LazyListView_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (LazyListView)");
    return 0;
}

int lua_register_cocos2dx_ui_mf_LazyListView(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"mf.LazyListView");
    tolua_cclass(tolua_S,"LazyListView","mf.LazyListView","ccui.ScrollView",nullptr);

    tolua_beginmodule(tolua_S,"LazyListView");
        tolua_function(tolua_S,"new",lua_cocos2dx_ui_mf_LazyListView_constructor);
        tolua_function(tolua_S,"setGravity",lua_cocos2dx_ui_mf_LazyListView_setGravity);
        tolua_function(tolua_S,"removeLastItem",lua_cocos2dx_ui_mf_LazyListView_removeLastItem);
        tolua_function(tolua_S,"getCurSelectedIndex",lua_cocos2dx_ui_mf_LazyListView_getCurSelectedIndex);
        tolua_function(tolua_S,"getItemsMargin",lua_cocos2dx_ui_mf_LazyListView_getItemsMargin);
        tolua_function(tolua_S,"getDataSource",lua_cocos2dx_ui_mf_LazyListView_getDataSource);
        tolua_function(tolua_S,"getIndex",lua_cocos2dx_ui_mf_LazyListView_getIndex);
        tolua_function(tolua_S,"pushBackCustomItem",lua_cocos2dx_ui_mf_LazyListView_pushBackCustomItem);
        tolua_function(tolua_S,"insertDefaultItem",lua_cocos2dx_ui_mf_LazyListView_insertDefaultItem);
        tolua_function(tolua_S,"addEventListener",lua_cocos2dx_ui_mf_LazyListView_addEventListener);
        tolua_function(tolua_S,"doLayout",lua_cocos2dx_ui_mf_LazyListView_doLayout);
        tolua_function(tolua_S,"removeAllItems",lua_cocos2dx_ui_mf_LazyListView_removeAllItems);
        tolua_function(tolua_S,"getItems",lua_cocos2dx_ui_mf_LazyListView_getItems);
        tolua_function(tolua_S,"setItemsMargin",lua_cocos2dx_ui_mf_LazyListView_setItemsMargin);
        tolua_function(tolua_S,"getItem",lua_cocos2dx_ui_mf_LazyListView_getItem);
        tolua_function(tolua_S,"removeItem",lua_cocos2dx_ui_mf_LazyListView_removeItem);
        tolua_function(tolua_S,"pushBackDefaultItem",lua_cocos2dx_ui_mf_LazyListView_pushBackDefaultItem);
        tolua_function(tolua_S,"refreshView",lua_cocos2dx_ui_mf_LazyListView_refreshView);
        tolua_function(tolua_S,"setDataSource",lua_cocos2dx_ui_mf_LazyListView_setDataSource);
        tolua_function(tolua_S,"setItemModel",lua_cocos2dx_ui_mf_LazyListView_setItemModel);
        tolua_function(tolua_S,"requestRefreshView",lua_cocos2dx_ui_mf_LazyListView_requestRefreshView);
        tolua_function(tolua_S,"insertCustomItem",lua_cocos2dx_ui_mf_LazyListView_insertCustomItem);
        tolua_function(tolua_S,"create", lua_cocos2dx_ui_mf_LazyListView_create);
        tolua_function(tolua_S,"createInstance", lua_cocos2dx_ui_mf_LazyListView_createInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::extension::mf::LazyListView).name();
    g_luaType[typeName] = "mf.LazyListView";
    g_typeCast["LazyListView"] = "mf.LazyListView";
    return 1;
}

int lua_cocos2dx_ui_mf_ImageViewExtended_updateRemoteImageUrl(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::mf::ImageViewExtended* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"mf.ImageViewExtended",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::mf::ImageViewExtended*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_ui_mf_ImageViewExtended_updateRemoteImageUrl'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "mf.ImageViewExtended:updateRemoteImageUrl");
        if(!ok)
            return 0;
        cobj->updateRemoteImageUrl(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "mf.ImageViewExtended:updateRemoteImageUrl",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ui_mf_ImageViewExtended_updateRemoteImageUrl'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_ui_mf_ImageViewExtended_loadTexture(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::mf::ImageViewExtended* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"mf.ImageViewExtended",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::mf::ImageViewExtended*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_ui_mf_ImageViewExtended_loadTexture'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "mf.ImageViewExtended:loadTexture");
        if(!ok)
            return 0;
        cobj->loadTexture(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        std::string arg0;
        cocos2d::ui::Widget::TextureResType arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "mf.ImageViewExtended:loadTexture");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "mf.ImageViewExtended:loadTexture");
        if(!ok)
            return 0;
        cobj->loadTexture(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "mf.ImageViewExtended:loadTexture",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ui_mf_ImageViewExtended_loadTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_ui_mf_ImageViewExtended_setScale9Enabled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::mf::ImageViewExtended* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"mf.ImageViewExtended",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::mf::ImageViewExtended*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_ui_mf_ImageViewExtended_setScale9Enabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "mf.ImageViewExtended:setScale9Enabled");
        if(!ok)
            return 0;
        cobj->setScale9Enabled(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "mf.ImageViewExtended:setScale9Enabled",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ui_mf_ImageViewExtended_setScale9Enabled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_ui_mf_ImageViewExtended_setTextureRect(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::mf::ImageViewExtended* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"mf.ImageViewExtended",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::mf::ImageViewExtended*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_ui_mf_ImageViewExtended_setTextureRect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Rect arg0;

        ok &= luaval_to_rect(tolua_S, 2, &arg0, "mf.ImageViewExtended:setTextureRect");
        if(!ok)
            return 0;
        cobj->setTextureRect(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "mf.ImageViewExtended:setTextureRect",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ui_mf_ImageViewExtended_setTextureRect'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_ui_mf_ImageViewExtended_setCapInsets(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::mf::ImageViewExtended* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"mf.ImageViewExtended",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::mf::ImageViewExtended*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_ui_mf_ImageViewExtended_setCapInsets'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Rect arg0;

        ok &= luaval_to_rect(tolua_S, 2, &arg0, "mf.ImageViewExtended:setCapInsets");
        if(!ok)
            return 0;
        cobj->setCapInsets(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "mf.ImageViewExtended:setCapInsets",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ui_mf_ImageViewExtended_setCapInsets'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_ui_mf_ImageViewExtended_getCapInsets(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::mf::ImageViewExtended* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"mf.ImageViewExtended",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::mf::ImageViewExtended*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_ui_mf_ImageViewExtended_getCapInsets'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Rect& ret = cobj->getCapInsets();
        rect_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "mf.ImageViewExtended:getCapInsets",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ui_mf_ImageViewExtended_getCapInsets'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_ui_mf_ImageViewExtended_setKeepAspectRatio(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::mf::ImageViewExtended* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"mf.ImageViewExtended",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::mf::ImageViewExtended*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_ui_mf_ImageViewExtended_setKeepAspectRatio'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "mf.ImageViewExtended:setKeepAspectRatio");
        if(!ok)
            return 0;
        cobj->setKeepAspectRatio(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "mf.ImageViewExtended:setKeepAspectRatio",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ui_mf_ImageViewExtended_setKeepAspectRatio'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_ui_mf_ImageViewExtended_isScale9Enabled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::mf::ImageViewExtended* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"mf.ImageViewExtended",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::mf::ImageViewExtended*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_ui_mf_ImageViewExtended_isScale9Enabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isScale9Enabled();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "mf.ImageViewExtended:isScale9Enabled",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ui_mf_ImageViewExtended_isScale9Enabled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_ui_mf_ImageViewExtended_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"mf.ImageViewExtended",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "mf.ImageViewExtended:create");
            if (!ok) { break; }
            cocos2d::extension::mf::ImageViewExtended* ret = cocos2d::extension::mf::ImageViewExtended::create(arg0);
            object_to_luaval<cocos2d::extension::mf::ImageViewExtended>(tolua_S, "mf.ImageViewExtended",(cocos2d::extension::mf::ImageViewExtended*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 2)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "mf.ImageViewExtended:create");
            if (!ok) { break; }
            cocos2d::ui::Widget::TextureResType arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "mf.ImageViewExtended:create");
            if (!ok) { break; }
            cocos2d::extension::mf::ImageViewExtended* ret = cocos2d::extension::mf::ImageViewExtended::create(arg0, arg1);
            object_to_luaval<cocos2d::extension::mf::ImageViewExtended>(tolua_S, "mf.ImageViewExtended",(cocos2d::extension::mf::ImageViewExtended*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            cocos2d::extension::mf::ImageViewExtended* ret = cocos2d::extension::mf::ImageViewExtended::create();
            object_to_luaval<cocos2d::extension::mf::ImageViewExtended>(tolua_S, "mf.ImageViewExtended",(cocos2d::extension::mf::ImageViewExtended*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 2)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "mf.ImageViewExtended:create");
            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1, "mf.ImageViewExtended:create");
            if (!ok) { break; }
            cocos2d::extension::mf::ImageViewExtended* ret = cocos2d::extension::mf::ImageViewExtended::create(arg0, arg1);
            object_to_luaval<cocos2d::extension::mf::ImageViewExtended>(tolua_S, "mf.ImageViewExtended",(cocos2d::extension::mf::ImageViewExtended*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 3)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "mf.ImageViewExtended:create");
            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1, "mf.ImageViewExtended:create");
            if (!ok) { break; }
            cocos2d::ui::Widget::TextureResType arg2;
            ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "mf.ImageViewExtended:create");
            if (!ok) { break; }
            cocos2d::extension::mf::ImageViewExtended* ret = cocos2d::extension::mf::ImageViewExtended::create(arg0, arg1, arg2);
            object_to_luaval<cocos2d::extension::mf::ImageViewExtended>(tolua_S, "mf.ImageViewExtended",(cocos2d::extension::mf::ImageViewExtended*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "mf.ImageViewExtended:create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ui_mf_ImageViewExtended_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_ui_mf_ImageViewExtended_createInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"mf.ImageViewExtended",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocos2d::Ref* ret = cocos2d::extension::mf::ImageViewExtended::createInstance();
        object_to_luaval<cocos2d::Ref>(tolua_S, "cc.Ref",(cocos2d::Ref*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "mf.ImageViewExtended:createInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ui_mf_ImageViewExtended_createInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_ui_mf_ImageViewExtended_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::mf::ImageViewExtended* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::extension::mf::ImageViewExtended();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"mf.ImageViewExtended");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "mf.ImageViewExtended:ImageViewExtended",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ui_mf_ImageViewExtended_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_ui_mf_ImageViewExtended_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ImageViewExtended)");
    return 0;
}

int lua_register_cocos2dx_ui_mf_ImageViewExtended(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"mf.ImageViewExtended");
    tolua_cclass(tolua_S,"ImageViewExtended","mf.ImageViewExtended","ccui.Widget",nullptr);

    tolua_beginmodule(tolua_S,"ImageViewExtended");
        tolua_function(tolua_S,"new",lua_cocos2dx_ui_mf_ImageViewExtended_constructor);
        tolua_function(tolua_S,"updateRemoteImageUrl",lua_cocos2dx_ui_mf_ImageViewExtended_updateRemoteImageUrl);
        tolua_function(tolua_S,"loadTexture",lua_cocos2dx_ui_mf_ImageViewExtended_loadTexture);
        tolua_function(tolua_S,"setScale9Enabled",lua_cocos2dx_ui_mf_ImageViewExtended_setScale9Enabled);
        tolua_function(tolua_S,"setTextureRect",lua_cocos2dx_ui_mf_ImageViewExtended_setTextureRect);
        tolua_function(tolua_S,"setCapInsets",lua_cocos2dx_ui_mf_ImageViewExtended_setCapInsets);
        tolua_function(tolua_S,"getCapInsets",lua_cocos2dx_ui_mf_ImageViewExtended_getCapInsets);
        tolua_function(tolua_S,"setKeepAspectRatio",lua_cocos2dx_ui_mf_ImageViewExtended_setKeepAspectRatio);
        tolua_function(tolua_S,"isScale9Enabled",lua_cocos2dx_ui_mf_ImageViewExtended_isScale9Enabled);
        tolua_function(tolua_S,"create", lua_cocos2dx_ui_mf_ImageViewExtended_create);
        tolua_function(tolua_S,"createInstance", lua_cocos2dx_ui_mf_ImageViewExtended_createInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::extension::mf::ImageViewExtended).name();
    g_luaType[typeName] = "mf.ImageViewExtended";
    g_typeCast["ImageViewExtended"] = "mf.ImageViewExtended";
    return 1;
}
TOLUA_API int register_all_cocos2dx_ui_mf(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"mf",0);
	tolua_beginmodule(tolua_S,"mf");

	lua_register_cocos2dx_ui_mf_ImageViewExtended(tolua_S);
	lua_register_cocos2dx_ui_mf_LazyListView(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

