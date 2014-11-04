LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := cocos_extensions_miguelferreira_static

LOCAL_MODULE_FILENAME := lib_extensions_miguelferreira

LOCAL_SRC_FILES := \
TextureDownloader.cpp \
UILazyListView.cpp \
UIImageViewExtended.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../..
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../cocos

LOCAL_STATIC_LIBRARIES := cocos2dx_internal_static
LOCAL_STATIC_LIBRARIES += cocos_network_static
LOCAL_STATIC_LIBRARIES += cocos_ui_static

include $(BUILD_STATIC_LIBRARY)
