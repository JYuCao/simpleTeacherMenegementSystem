#ifndef _SMS_LINKLIST_H
#define _SMS_LINKLIST_H

#include <windows.h>
#include "Linklist.h"

/* 函数声明 */
// 显示菜单
void showMenu(void);

// 添加新信息
void addInfo(List * plist);

// 清空输入缓冲区
void eatline(void);

#endif
