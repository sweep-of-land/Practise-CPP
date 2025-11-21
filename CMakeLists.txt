cmake_minimum_required(VERSION 3.20)
project(Practise-CPP CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 使用MSVC兼容模式
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")

# 设置默认构建类型
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# 为不同配置设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Release)

# 通用警告设置，适用于所有编译器
if(MSVC OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang" AND CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC"))
    # MSVC 或 clang-cl
    add_compile_options(/W4)
    # clang-cl 需要额外的 clang 原生选项来检测未初始化变量
    add_compile_options(
        /clang:-Wall 
        /clang:-Wextra 
        /clang:-Wpedantic
        /clang:-Wuninitialized
        /clang:-Wshadow
        /clang:-Wconversion
    )
else()
    # GCC 或普通 Clang
    add_compile_options(-Wall -Wextra -Wpedantic -Wuninitialized -Wshadow -Wconversion)
endif()

add_executable(${PROJECT_NAME} 1119-Effective-Modern.cpp)
