#include "TMS_Linklist.h"
#include <stdlib.h>
#include <string.h>

/* 函数定义 */
// 显示菜单
void showMenu(void)
{
    system("cls");

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

    printf("Enter teacher's name: ");
    scanf_s("%s", temp, 15);

    tempItem.name = (char *)malloc(sizeof(char) * (strlen(temp)+1));
    strcpy(tempItem.name, temp);
    
    printf("Enter teacher's lesson: ");
    scanf_s("%s", temp, 15);

    tempItem.lesson = (char *)malloc(sizeof(char) * (strlen(temp)+1));
    strcpy(tempItem.lesson, temp);

    AddItem(tempItem, plist);
}

// 清空输入缓冲区
void eatline(void)
{
    while (getchar() != '\n')
        ;
}
