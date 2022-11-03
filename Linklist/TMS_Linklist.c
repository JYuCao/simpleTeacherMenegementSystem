#include "TMS_Linklist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 内部函数声明 */
// 打印节点内容
static void NodePrint(Item item);

// 清空输入缓冲区
static void eatline(void);

// 暂停
static void pause(void);

// 延时
static void delay(void);

// 清屏
static void clear(void);

/* 函数定义 */
// 显示菜单
void showMenu(List *plist)
{
    char selected = '0';

    while (selected != '4')
    {
        clear();

        printf("*******************************************************\n");
        printf("1. Add new information\n");
        printf("2. List all informations\n");
        printf("3. Delete information\n");
        printf("4. Quit\n");
        printf("Enter your selection: ");

        fflush(stdin);
        selected = getchar();
        eatline();
        switch (selected)
        {
        case '1':
            if (addInfo(plist))
                printf("Add information success!\n");
            else
                printf("Add information failure!\n");
            pause();
            break;
        case '2':
            showInfo(plist);
            pause();
            break;
        case '3':
            if (delInfo(plist))
                printf("Delete information success!\n");
            else
                printf("Delete information failure!\n");
            pause();
            break;
        case '4':
            exit(EXIT_SUCCESS);
            break;
        default:
            puts("Error input!");
            delay();
            continue;
        }
    }
}

// 添加新信息
bool addInfo(List *plist)
{
    char temp[20];
    Item tempItem;

    printf("Enter teacher's name(< 15 characters): ");
    scanf_s("%s", temp, 15);

    tempItem.name = (char *)malloc(sizeof(char) * (strlen(temp) + 1));
    if (!tempItem.name)
        return false;
    strcpy(tempItem.name, temp);

    printf("Enter teacher's lesson(< 15 characters): ");
    scanf_s("%s", temp, 15);

    tempItem.lesson = (char *)malloc(sizeof(char) * (strlen(temp) + 1));
    if (!tempItem.lesson)
        return false;
    strcpy(tempItem.lesson, temp);

    if (!AddItem(tempItem, plist))
        return false;

    return true;
}

// 打印所有信息
void showInfo(List *plist)
{
    puts("All information list:");
    Traverse(plist, NodePrint);
}

// 删除信息
bool delInfo(List *plist)
{
    char selected;
    char temp[15], temp2[15];
    Node *tNode = plist->head;
    int i = 0;
    bool status = false;

    showInfo(plist);
    printf("\nWhat do you want to based on to delete items?\n");
    printf("1. teachar's name\n2. teachar's lesson\n3. both name and lesson\n4. quit\n");
    printf("Your selection: ");

    selected = getchar();
    eatline();
    switch (selected)
    {
    case '1':
        printf("Enter teacher's name(< 15 characters): ");
        scanf_s("%s", temp, 15);
        while (tNode)
        {
            if (!strcmp(tNode->item.name, temp))
            {
                DeleteItem(plist, i--);
                if (!status)
                    status = true;
            }
            ++i;
            tNode = tNode->next;
        }
        break;
    case '2':
        printf("Enter teacher's lesson(< 15 characters): ");
        scanf_s("%s", temp, 15);
        while (tNode)
        {
            if (!strcmp(tNode->item.lesson, temp))
            {
                DeleteItem(plist, i--);
                if (!status)
                    status = true;
            }
            ++i;
            tNode = tNode->next;
        }
        break;
    case '3':
        printf("Enter teacher's name(< 15 characters): ");
        scanf_s("%s", temp, 15);
        printf("Enter teacher's lesson(< 15 characters): ");
        scanf_s("%s", temp2, 15);
        while (tNode)
        {
            if (!strcmp(tNode->item.name, temp) && !strcmp(tNode->item.lesson, temp2))
            {
                DeleteItem(plist, i--);
                if (!status)
                    status = true;
            }
            ++i;
            tNode = tNode->next;
        }
        break;
    case '4':
        break;
    default:
        puts("Error input!");
        delay();
    }
    return status;
}

/* 内部函数定义 */
// 清空输入缓冲区
static void eatline(void)
{
    while (getchar() != '\n')
        ;
}

// 暂停
static void pause(void)
{
    Sleep(500);
    system("pause");
}

// 延时
static void delay(void)
{
    Sleep(2000);
}

// 清屏
static void clear(void)
{
    system("cls");
}

// 打印节点内容
static void NodePrint(Item item)
{
    printf("Teacher %s\tis teaching %s.\n",
           item.name, item.lesson);
}
