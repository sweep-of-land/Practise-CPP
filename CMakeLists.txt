cmake_minimum_required(VERSION 3.20)
project(Practise-CPP CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")

# =========================================================
# 全局预处理器定义 (新增部分)
# =========================================================
# 1. _CRT_SECURE_NO_WARNINGS: 允许使用 sprintf 等不安全函数
# 2. _CRT_NONSTDC_NO_DEPRECATE: 允许使用 write, fileno, isatty 等 POSIX 函数名
add_compile_definitions(
    _CRT_SECURE_NO_WARNINGS
    _CRT_NONSTDC_NO_DEPRECATE
)

# =========================================================
# 警告选项调整
# =========================================================
# 注意：我移除了 /clang:-Wconversion 等过于严格的检查，
# 因为 Blender 的 C 风格代码会触发大量此类警告。
if(MSVC OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang" AND CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC"))
    add_compile_options(/W3) # 将 W4 降级为 W3，或者保持 W4 但忽略特定警告
    add_compile_options(
        /clang:-Wall 
        /clang:-Wextra 
        /clang:-Wno-unused-function
        /clang:-Wno-unused-parameter
        /clang:-Wno-sign-compare
        /clang:-Wno-missing-field-initializers
        /clang:-Wno-zero-length-array     # 允许 char match[0]
        /clang:-Wno-deprecated-declarations # 防止某些遗漏的弃用警告
    )
else()
    add_compile_options(-Wall -Wextra)
endif()

# 配置 CLog
set(CLOG_SRC clog/clog.cc)
include_directories(${CMAKE_SOURCE_DIR}/clog) 

add_executable(${PROJECT_NAME} 
    1119-Effective-Modern.cpp 
    ${CLOG_SRC}
)
