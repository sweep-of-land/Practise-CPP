#include "clog/CLG_log.h"  // 引入头文件
#include <iostream>

#ifdef _WIN32
#  include <windows.h>
#endif
// 1. 注册一个日志引用 (Log Reference)
// 这是一个全局变量，用于标记日志的类别，例如 "bf.io", "bf.render"
// 在 Blender 源码中，这通常放在每个文件的顶部
static CLG_LogRef *LOG_MY_TEST = NULL;

void init_logging()
{
#ifdef _WIN32
  SetConsoleOutputCP(65001);
#endif
  // 2. 初始化 CLOG 系统
  CLG_init();

  // 3. 注册刚才定义的日志类别
  // "my.test" 是你在终端看到的标识符
  static CLG_LogRef ref = {"my.test"};
  LOG_MY_TEST = &ref;
  CLG_logref_register(LOG_MY_TEST);

  // 可选：设置日志级别 (默认通常是 WARN)
  // 设置为 INFO 可以看到 INFO 级别的日志
  CLG_level_set(CLG_LEVEL_INFO);

  // 启用颜色 (Windows 10+ 终端支持)
  CLG_output_use_basename_set(1);   // 只显示文件名，不显示全路径
  CLG_output_use_timestamp_set(1);  // 显示时间戳
}

void cleanup_logging()
{
  CLG_exit();
}

int main()
{
  init_logging();

  // 使用示例
  // 格式: CLOG_INFO(日志引用, 格式化字符串, 参数...)

  CLOG_INFO(LOG_MY_TEST, "系统启动完成，版本: %d", 2024);
  CLOG_WARN(LOG_MY_TEST, "这是一个警告信息，注意变量 x = %d", 42);
  CLOG_ERROR(LOG_MY_TEST, "发生了一个错误！");

  // 也可以用字符串宏
  CLOG_STR_INFO(LOG_MY_TEST, "这是一条纯字符串日志");

  // 模拟一些逻辑
  std::cout << "--- 程序正常输出 ---" << std::endl;

  cleanup_logging();
  return 0;
}
