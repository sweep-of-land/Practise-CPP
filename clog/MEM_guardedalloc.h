/* MEM_guardedalloc.h - 修复版 */
#pragma once

#include <cstdio>
#include <cstdlib>
#include <cstring>


// 基础类型定义 (与你的 CMake 或源码保持一致)
using uint = unsigned int;

// 1. 内存统计桩函数
inline size_t MEM_get_memory_in_use()
{
  return 0;
}

// 2. 核心分配器封装

// [修复 Error 1] MEM_freeN 需要能接受 const 指针
// C++ 中 free 需要 void*，所以我们需要 const_cast 去掉 const 属性
inline void MEM_freeN(const void *ptr)
{
  if (ptr)
    free(const_cast<void *>(ptr));
}

// 模拟 MEM_mallocN
inline void *MEM_mallocN(size_t len, const char *str)
{
  (void)str;
  return malloc(len);
}

// 模拟 MEM_reallocN
inline void *MEM_reallocN(void *vmem, size_t len)
{
  return realloc(vmem, len);
}

// [修复 Error 2] 增加非模板的原始 calloc 版本
// 对应源码调用: MEM_callocN(sizeof(...), __func__)
inline void *MEM_callocN(size_t len, const char *str)
{
  (void)str;
  return calloc(1, len);
}

// 3. 模板辅助函数

// 模拟 MEM_callocN<T> (分配单个对象)
template<typename T> T *MEM_callocN(const char *str)
{
  (void)str;
  return (T *)calloc(1, sizeof(T));
}

// 模拟 MEM_calloc_arrayN<T> (分配数组)
template<typename T> T *MEM_calloc_arrayN(size_t len, const char *str)
{
  (void)str;
  return (T *)calloc(len, sizeof(T));
}

// 模拟 MEM_malloc_arrayN<T> (分配数组，不清零)
template<typename T> T *MEM_malloc_arrayN(size_t len, const char *str)
{
  (void)str;
  return (T *)malloc(len * sizeof(T));
}
