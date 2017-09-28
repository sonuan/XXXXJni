LOCAL_PATH := $(call my-dir) # 源文件在开发树中的位置, my-dir表示返回当前目录
include $(CLEAR_VARS) # 初始化或取消定义与模块相关的变量。如，清除 LOCAL_XXX 变量，但不会清除 LOCAL_PATH。在描述每个模块之前，必须声明（重新声明）此变量
LOCAL_MODULE := helloworld # 构建的模块的名称，每个模块名称必须唯一，且不含任何空格
LOCAL_SRC_FILES := helloworld.cpp # 枚举源文件，以空格分隔多个文件
include $(BUILD_SHARED_LIBRARY) # 收集您自最近 include 后在 LOCAL_XXX 变量中定义的所有信息


