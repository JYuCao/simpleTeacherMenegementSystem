#ifndef _SMS_LINKLIST_H
#define _SMS_LINKLIST_H

#include <windows.h>
#include "Linklist.h"

/* 函数声明 */
// 显示菜单
void showMenu(void);

// 添加新信息
bool addInfo(List * plist);

// 打印所有信息
void showInfo(List * plist);

// 删除信息
bool delInfo(List * plist);

// 清空输入缓冲区
void eatline(void);

// 延时
void delay(void);

// 清屏
void clear(void);

#endif
