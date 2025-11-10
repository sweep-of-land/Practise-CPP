cmake_minimum_required(VERSION 3.20)
project(Practise-CPP CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 23)
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

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    # 基础警告选项
    add_compile_options(
        -Wall 
        -Wextra 
        -Wpedantic
        -Werror=return-type
        -Werror=uninitialized
    )
    
    # 关闭C++98兼容性警告
    add_compile_options(-Wno-c++98-compat -Wno-c++98-compat-pedantic)
    
    # 为clang-cl设置正确的C++标准
    if(CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
        # clang-cl使用MSVC风格参数
        add_compile_options(/std:c++23)
    else()
        # 其他clang编译器使用标准参数
        add_compile_options(-std=c++23)
    endif()
    
    # 只在Release配置中启用sanitizer
    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        # clang-cl 识别MSVC参数，fsanitize不兼容
        if(NOT CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
            if(CMAKE_BUILD_TYPE STREQUAL "Release")
                add_compile_options(-fsanitize=address -fsanitize=undefined)
                add_link_options(-fsanitize=address -fsanitize=undefined)
            endif()
        endif()
    endif()
endif()

add_executable(${PROJECT_NAME} 1109.cpp)
