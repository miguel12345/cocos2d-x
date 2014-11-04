#include "lua_cocos2dx_extension.hpp"
#include "DownloaderExtended.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_cocos2dx_extension_DownloaderExtended_downloadAsync(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::DownloaderExtended* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DownloaderExtended",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::DownloaderExtended*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extension_DownloaderExtended_downloadAsync'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.DownloaderExtended:downloadAsync");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "cc.DownloaderExtended:downloadAsync");
        if(!ok)
            return 0;
        std::weak_ptr<cocos2d::extension::DownloaderExtended::DownloadHandler> ret = cobj->downloadAsync(arg0, arg1);
        object_to_luaval<std::weak_ptr<cocos2d::extension::DownloaderExtended::DownloadHandler>>(tolua_S, "std::weak_ptr<cocos2d::extension::DownloaderExtended::DownloadHandler>",(std::weak_ptr<cocos2d::extension::DownloaderExtended::DownloadHandler>)ret);
        return 1;
    }
    if (argc == 3) 
    {
        std::string arg0;
        std::string arg1;
        std::string arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.DownloaderExtended:downloadAsync");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "cc.DownloaderExtended:downloadAsync");

        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "cc.DownloaderExtended:downloadAsync");
        if(!ok)
            return 0;
        std::weak_ptr<cocos2d::extension::DownloaderExtended::DownloadHandler> ret = cobj->downloadAsync(arg0, arg1, arg2);
        object_to_luaval<std::weak_ptr<cocos2d::extension::DownloaderExtended::DownloadHandler>>(tolua_S, "std::weak_ptr<cocos2d::extension::DownloaderExtended::DownloadHandler>",(std::weak_ptr<cocos2d::extension::DownloaderExtended::DownloadHandler>)ret);
        return 1;
    }
    if (argc == 4) 
    {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        cocos2d::extension::DownloaderExtended::CacheStrategy arg3;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.DownloaderExtended:downloadAsync");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "cc.DownloaderExtended:downloadAsync");

        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "cc.DownloaderExtended:downloadAsync");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "cc.DownloaderExtended:downloadAsync");
        if(!ok)
            return 0;
        std::weak_ptr<cocos2d::extension::DownloaderExtended::DownloadHandler> ret = cobj->downloadAsync(arg0, arg1, arg2, arg3);
        object_to_luaval<std::weak_ptr<cocos2d::extension::DownloaderExtended::DownloadHandler>>(tolua_S, "std::weak_ptr<cocos2d::extension::DownloaderExtended::DownloadHandler>",(std::weak_ptr<cocos2d::extension::DownloaderExtended::DownloadHandler>)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cc.DownloaderExtended:downloadAsync",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extension_DownloaderExtended_downloadAsync'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extension_DownloaderExtended_getSuccessCallback(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::DownloaderExtended* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DownloaderExtended",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::DownloaderExtended*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extension_DownloaderExtended_getSuccessCallback'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::extension::DownloaderExtended::SuccessCallback ret = cobj->getSuccessCallback();
        #pragma warning NO CONVERSION FROM NATIVE FOR std::function;
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cc.DownloaderExtended:getSuccessCallback",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extension_DownloaderExtended_getSuccessCallback'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extension_DownloaderExtended_setErrorCallback(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::DownloaderExtended* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DownloaderExtended",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::DownloaderExtended*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extension_DownloaderExtended_setErrorCallback'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::function<void (const cocos2d::extension::DownloaderExtended::Error &)> arg0;

        do {
			// Lambda binding for lua is not supported.
			assert(false);
		} while(0)
		;
        if(!ok)
            return 0;
        cobj->setErrorCallback(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cc.DownloaderExtended:setErrorCallback",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extension_DownloaderExtended_setErrorCallback'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extension_DownloaderExtended_getContentSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::DownloaderExtended* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DownloaderExtended",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::DownloaderExtended*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extension_DownloaderExtended_getContentSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.DownloaderExtended:getContentSize");
        if(!ok)
            return 0;
        long ret = cobj->getContentSize(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cc.DownloaderExtended:getContentSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extension_DownloaderExtended_getContentSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extension_DownloaderExtended_setProgressCallback(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::DownloaderExtended* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DownloaderExtended",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::DownloaderExtended*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extension_DownloaderExtended_setProgressCallback'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::function<void (double, double, const std::basic_string<char> &, const std::basic_string<char> &)> arg0;

        do {
			// Lambda binding for lua is not supported.
			assert(false);
		} while(0)
		;
        if(!ok)
            return 0;
        cobj->setProgressCallback(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cc.DownloaderExtended:setProgressCallback",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extension_DownloaderExtended_setProgressCallback'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extension_DownloaderExtended_downloadToBufferSync(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::DownloaderExtended* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DownloaderExtended",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::DownloaderExtended*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extension_DownloaderExtended_downloadToBufferSync'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        std::string arg0;
        unsigned char* arg1;
        long arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.DownloaderExtended:downloadToBufferSync");

        #pragma warning NO CONVERSION TO NATIVE FOR unsigned char*
		ok = false;

        ok &= luaval_to_long(tolua_S, 4, &arg2, "cc.DownloaderExtended:downloadToBufferSync");
        if(!ok)
            return 0;
        cobj->downloadToBufferSync(arg0, arg1, arg2);
        return 0;
    }
    if (argc == 4) 
    {
        std::string arg0;
        unsigned char* arg1;
        long arg2;
        std::string arg3;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.DownloaderExtended:downloadToBufferSync");

        #pragma warning NO CONVERSION TO NATIVE FOR unsigned char*
		ok = false;

        ok &= luaval_to_long(tolua_S, 4, &arg2, "cc.DownloaderExtended:downloadToBufferSync");

        ok &= luaval_to_std_string(tolua_S, 5,&arg3, "cc.DownloaderExtended:downloadToBufferSync");
        if(!ok)
            return 0;
        cobj->downloadToBufferSync(arg0, arg1, arg2, arg3);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cc.DownloaderExtended:downloadToBufferSync",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extension_DownloaderExtended_downloadToBufferSync'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extension_DownloaderExtended_getErrorCallback(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::DownloaderExtended* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DownloaderExtended",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::DownloaderExtended*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extension_DownloaderExtended_getErrorCallback'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::extension::DownloaderExtended::ErrorCallback ret = cobj->getErrorCallback();
        #pragma warning NO CONVERSION FROM NATIVE FOR std::function;
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cc.DownloaderExtended:getErrorCallback",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extension_DownloaderExtended_getErrorCallback'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extension_DownloaderExtended_batchDownloadSync(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::DownloaderExtended* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DownloaderExtended",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::DownloaderExtended*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extension_DownloaderExtended_batchDownloadSync'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::unordered_map<std::basic_string<char>, cocos2d::extension::DownloaderExtended::DownloadUnit, std::hash<string>, std::equal_to<std::basic_string<char> >, std::allocator<std::pair<const std::basic_string<char>, cocos2d::extension::DownloaderExtended::DownloadUnit> > > arg0;

        ok &= luaval_to_object<std::unordered_map<std::basic_string<char>, cocos2d::extension::DownloaderExtended::DownloadUnit, std::hash<string>, std::equal_to<std::basic_string<char> >, std::allocator<std::pair<const std::basic_string<char>, cocos2d::extension::DownloaderExtended::DownloadUnit> > >>(tolua_S, 2, "std::unordered_map<std::basic_string<char>, cocos2d::extension::DownloaderExtended::DownloadUnit, std::hash<string>, std::equal_to<std::basic_string<char> >, std::allocator<std::pair<const std::basic_string<char>, cocos2d::extension::DownloaderExtended::DownloadUnit> > >",&arg0);
        if(!ok)
            return 0;
        cobj->batchDownloadSync(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        std::unordered_map<std::basic_string<char>, cocos2d::extension::DownloaderExtended::DownloadUnit, std::hash<string>, std::equal_to<std::basic_string<char> >, std::allocator<std::pair<const std::basic_string<char>, cocos2d::extension::DownloaderExtended::DownloadUnit> > > arg0;
        std::string arg1;

        ok &= luaval_to_object<std::unordered_map<std::basic_string<char>, cocos2d::extension::DownloaderExtended::DownloadUnit, std::hash<string>, std::equal_to<std::basic_string<char> >, std::allocator<std::pair<const std::basic_string<char>, cocos2d::extension::DownloaderExtended::DownloadUnit> > >>(tolua_S, 2, "std::unordered_map<std::basic_string<char>, cocos2d::extension::DownloaderExtended::DownloadUnit, std::hash<string>, std::equal_to<std::basic_string<char> >, std::allocator<std::pair<const std::basic_string<char>, cocos2d::extension::DownloaderExtended::DownloadUnit> > >",&arg0);

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "cc.DownloaderExtended:batchDownloadSync");
        if(!ok)
            return 0;
        cobj->batchDownloadSync(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cc.DownloaderExtended:batchDownloadSync",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extension_DownloaderExtended_batchDownloadSync'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extension_DownloaderExtended_getProgressCallback(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::DownloaderExtended* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DownloaderExtended",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::DownloaderExtended*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extension_DownloaderExtended_getProgressCallback'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::extension::DownloaderExtended::ProgressCallback ret = cobj->getProgressCallback();
        #pragma warning NO CONVERSION FROM NATIVE FOR std::function;
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cc.DownloaderExtended:getProgressCallback",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extension_DownloaderExtended_getProgressCallback'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extension_DownloaderExtended_downloadSync(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::DownloaderExtended* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DownloaderExtended",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::DownloaderExtended*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extension_DownloaderExtended_downloadSync'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.DownloaderExtended:downloadSync");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "cc.DownloaderExtended:downloadSync");
        if(!ok)
            return 0;
        cobj->downloadSync(arg0, arg1);
        return 0;
    }
    if (argc == 3) 
    {
        std::string arg0;
        std::string arg1;
        std::string arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.DownloaderExtended:downloadSync");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "cc.DownloaderExtended:downloadSync");

        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "cc.DownloaderExtended:downloadSync");
        if(!ok)
            return 0;
        cobj->downloadSync(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cc.DownloaderExtended:downloadSync",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extension_DownloaderExtended_downloadSync'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extension_DownloaderExtended_setSuccessCallback(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::DownloaderExtended* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DownloaderExtended",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::DownloaderExtended*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extension_DownloaderExtended_setSuccessCallback'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::function<void (const std::basic_string<char> &, const std::basic_string<char> &, const std::basic_string<char> &)> arg0;

        do {
			// Lambda binding for lua is not supported.
			assert(false);
		} while(0)
		;
        if(!ok)
            return 0;
        cobj->setSuccessCallback(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cc.DownloaderExtended:setSuccessCallback",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extension_DownloaderExtended_setSuccessCallback'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extension_DownloaderExtended_getConnectionTimeout(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::DownloaderExtended* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DownloaderExtended",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::DownloaderExtended*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extension_DownloaderExtended_getConnectionTimeout'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getConnectionTimeout();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cc.DownloaderExtended:getConnectionTimeout",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extension_DownloaderExtended_getConnectionTimeout'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extension_DownloaderExtended_batchDownloadAsync(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::DownloaderExtended* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DownloaderExtended",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::DownloaderExtended*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extension_DownloaderExtended_batchDownloadAsync'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::unordered_map<std::basic_string<char>, cocos2d::extension::DownloaderExtended::DownloadUnit, std::hash<string>, std::equal_to<std::basic_string<char> >, std::allocator<std::pair<const std::basic_string<char>, cocos2d::extension::DownloaderExtended::DownloadUnit> > > arg0;

        ok &= luaval_to_object<std::unordered_map<std::basic_string<char>, cocos2d::extension::DownloaderExtended::DownloadUnit, std::hash<string>, std::equal_to<std::basic_string<char> >, std::allocator<std::pair<const std::basic_string<char>, cocos2d::extension::DownloaderExtended::DownloadUnit> > >>(tolua_S, 2, "std::unordered_map<std::basic_string<char>, cocos2d::extension::DownloaderExtended::DownloadUnit, std::hash<string>, std::equal_to<std::basic_string<char> >, std::allocator<std::pair<const std::basic_string<char>, cocos2d::extension::DownloaderExtended::DownloadUnit> > >",&arg0);
        if(!ok)
            return 0;
        cobj->batchDownloadAsync(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        std::unordered_map<std::basic_string<char>, cocos2d::extension::DownloaderExtended::DownloadUnit, std::hash<string>, std::equal_to<std::basic_string<char> >, std::allocator<std::pair<const std::basic_string<char>, cocos2d::extension::DownloaderExtended::DownloadUnit> > > arg0;
        std::string arg1;

        ok &= luaval_to_object<std::unordered_map<std::basic_string<char>, cocos2d::extension::DownloaderExtended::DownloadUnit, std::hash<string>, std::equal_to<std::basic_string<char> >, std::allocator<std::pair<const std::basic_string<char>, cocos2d::extension::DownloaderExtended::DownloadUnit> > >>(tolua_S, 2, "std::unordered_map<std::basic_string<char>, cocos2d::extension::DownloaderExtended::DownloadUnit, std::hash<string>, std::equal_to<std::basic_string<char> >, std::allocator<std::pair<const std::basic_string<char>, cocos2d::extension::DownloaderExtended::DownloadUnit> > >",&arg0);

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "cc.DownloaderExtended:batchDownloadAsync");
        if(!ok)
            return 0;
        cobj->batchDownloadAsync(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cc.DownloaderExtended:batchDownloadAsync",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extension_DownloaderExtended_batchDownloadAsync'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extension_DownloaderExtended_setConnectionTimeout(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::DownloaderExtended* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DownloaderExtended",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::DownloaderExtended*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extension_DownloaderExtended_setConnectionTimeout'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "cc.DownloaderExtended:setConnectionTimeout");
        if(!ok)
            return 0;
        cobj->setConnectionTimeout(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cc.DownloaderExtended:setConnectionTimeout",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extension_DownloaderExtended_setConnectionTimeout'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extension_DownloaderExtended_downloadToBufferAsync(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::DownloaderExtended* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DownloaderExtended",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::extension::DownloaderExtended*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extension_DownloaderExtended_downloadToBufferAsync'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        std::string arg0;
        unsigned char* arg1;
        long arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.DownloaderExtended:downloadToBufferAsync");

        #pragma warning NO CONVERSION TO NATIVE FOR unsigned char*
		ok = false;

        ok &= luaval_to_long(tolua_S, 4, &arg2, "cc.DownloaderExtended:downloadToBufferAsync");
        if(!ok)
            return 0;
        cobj->downloadToBufferAsync(arg0, arg1, arg2);
        return 0;
    }
    if (argc == 4) 
    {
        std::string arg0;
        unsigned char* arg1;
        long arg2;
        std::string arg3;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.DownloaderExtended:downloadToBufferAsync");

        #pragma warning NO CONVERSION TO NATIVE FOR unsigned char*
		ok = false;

        ok &= luaval_to_long(tolua_S, 4, &arg2, "cc.DownloaderExtended:downloadToBufferAsync");

        ok &= luaval_to_std_string(tolua_S, 5,&arg3, "cc.DownloaderExtended:downloadToBufferAsync");
        if(!ok)
            return 0;
        cobj->downloadToBufferAsync(arg0, arg1, arg2, arg3);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cc.DownloaderExtended:downloadToBufferAsync",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extension_DownloaderExtended_downloadToBufferAsync'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extension_DownloaderExtended_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::extension::DownloaderExtended* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::extension::DownloaderExtended();
        tolua_pushusertype(tolua_S,(void*)cobj,"cc.DownloaderExtended");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cc.DownloaderExtended:DownloaderExtended",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extension_DownloaderExtended_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_extension_DownloaderExtended_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (DownloaderExtended)");
    return 0;
}

int lua_register_cocos2dx_extension_DownloaderExtended(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.DownloaderExtended");
    tolua_cclass(tolua_S,"DownloaderExtended","cc.DownloaderExtended","std::enable_shared_from_this<cocos2d::extension::DownloaderExtended>",nullptr);

    tolua_beginmodule(tolua_S,"DownloaderExtended");
        tolua_function(tolua_S,"new",lua_cocos2dx_extension_DownloaderExtended_constructor);
        tolua_function(tolua_S,"downloadAsync",lua_cocos2dx_extension_DownloaderExtended_downloadAsync);
        tolua_function(tolua_S,"getSuccessCallback",lua_cocos2dx_extension_DownloaderExtended_getSuccessCallback);
        tolua_function(tolua_S,"setErrorCallback",lua_cocos2dx_extension_DownloaderExtended_setErrorCallback);
        tolua_function(tolua_S,"getContentSize",lua_cocos2dx_extension_DownloaderExtended_getContentSize);
        tolua_function(tolua_S,"setProgressCallback",lua_cocos2dx_extension_DownloaderExtended_setProgressCallback);
        tolua_function(tolua_S,"downloadToBufferSync",lua_cocos2dx_extension_DownloaderExtended_downloadToBufferSync);
        tolua_function(tolua_S,"getErrorCallback",lua_cocos2dx_extension_DownloaderExtended_getErrorCallback);
        tolua_function(tolua_S,"batchDownloadSync",lua_cocos2dx_extension_DownloaderExtended_batchDownloadSync);
        tolua_function(tolua_S,"getProgressCallback",lua_cocos2dx_extension_DownloaderExtended_getProgressCallback);
        tolua_function(tolua_S,"downloadSync",lua_cocos2dx_extension_DownloaderExtended_downloadSync);
        tolua_function(tolua_S,"setSuccessCallback",lua_cocos2dx_extension_DownloaderExtended_setSuccessCallback);
        tolua_function(tolua_S,"getConnectionTimeout",lua_cocos2dx_extension_DownloaderExtended_getConnectionTimeout);
        tolua_function(tolua_S,"batchDownloadAsync",lua_cocos2dx_extension_DownloaderExtended_batchDownloadAsync);
        tolua_function(tolua_S,"setConnectionTimeout",lua_cocos2dx_extension_DownloaderExtended_setConnectionTimeout);
        tolua_function(tolua_S,"downloadToBufferAsync",lua_cocos2dx_extension_DownloaderExtended_downloadToBufferAsync);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::extension::DownloaderExtended).name();
    g_luaType[typeName] = "cc.DownloaderExtended";
    g_typeCast["DownloaderExtended"] = "cc.DownloaderExtended";
    return 1;
}
TOLUA_API int register_all_cocos2dx_extension(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"cc",0);
	tolua_beginmodule(tolua_S,"cc");

	lua_register_cocos2dx_extension_DownloaderExtended(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

