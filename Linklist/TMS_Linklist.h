#ifndef _SMS_LINKLIST_H
#define _SMS_LINKLIST_H

#include <windows.h>
#include "Linklist.h"

/* 函数声明 */
// 显示菜单
void showMenu(List * plist);

// 添加新信息
bool addInfo(List * plist);

// 打印所有信息
bool showInfo(List * plist);

// 删除信息
bool delInfo(List * plist);

// 初始添加信息
void addSomeInfo(List * plist);

#endif
