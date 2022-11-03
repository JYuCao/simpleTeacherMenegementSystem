#include "TMS_Linklist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 内部函数声明 */
//打印节点内容
static void NodePrint(Item * item);

/* 函数定义 */
// 显示菜单
void showMenu(void)
{
    clear();

    printf("*******************************************************\n");
    printf("1. Add new information\n");
    printf("2. List all informations\n");
    printf("3. Delete information\n");
    printf("4. Quit\n");
    printf("Enter your selection: ");
}

// 添加新信息
void addInfo(List * plist)
{
    char temp[20];
    Item tempItem;

    printf("Enter teacher's name(< 15 characters): ");
    scanf_s("%s", temp, 15);

    tempItem.name = (char *)malloc(sizeof(char) * (strlen(temp)+1));
    strcpy(tempItem.name, temp);
    
    printf("Enter teacher's lesson(< 15 characters): ");
    scanf_s("%s", temp, 15);

    tempItem.lesson = (char *)malloc(sizeof(char) * (strlen(temp)+1));
    strcpy(tempItem.lesson, temp);

    AddItem(tempItem, plist);
    printf("Add successfully!\n");
    delay();
}

// 打印所有信息
void showInfo(List * plist)
{
    Traverse(plist, NodePrint);
}

// 删除信息
void delInfo(List * plist)
{

}

// 清空输入缓冲区
void eatline(void)
{
    while (getchar() != '\n')
        ;
}

//延时
void delay(void)
{
    Sleep(3000);
}

// 清屏
void clear(void)
{
    system("cls");
}

/* 内部函数定义 */
//打印节点内容
static void NodePrint(Item * item)
{
    printf("Teacher %s\tis teaching %s.\n",
        item->name, item->lesson);
}