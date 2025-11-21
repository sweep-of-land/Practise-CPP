#include "clog/CLG_log.h"  // 引入头文件
#include <iostream>

int main()
{
  CLG_LogRef *LOG_MY_TEST = init_logging("My test");

  CLOG_INFO(LOG_MY_TEST, "系统版本: %d", 2024);
  CLOG_WARN(LOG_MY_TEST, "警告，注意变量 x = %d", 42);
  CLOG_ERROR(LOG_MY_TEST, "发生错误！");
  //   CLOG_FATAL(LOG_MY_TEST, "发生严重错误!!!!!！已中止");

  // 也可以用字符串宏
  CLOG_STR_INFO(LOG_MY_TEST, "这是一条日志");

  CLG_exit();
  return 0;
}
