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
        printf("2. Search for informations\n");
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
            if (showInfo(plist))
                printf("Search for information success!\n");
            else
                printf("Search for information failure!\n");
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
bool showInfo(List *plist)
{
    char selected;
    char temp[15], temp2[15];
    Node *tNode = plist->head;
    bool status = false;

    printf("\nWhat do you want to based on to search for items?\n");
    printf("1. List all infomations\n2. teachar's name\n3. teachar's lesson\n4. both name and lesson\n5. quit\n");
    printf("Your selection: ");

    selected = getchar();
    eatline();
    switch (selected)
    {
    case '1':
            Traverse(plist, NodePrint);
            status = true;
            break;
    case '2':
        printf("Enter teacher's name(< 15 characters): ");
        scanf_s("%s", temp, 15);
        while (tNode)
        {
            if (!strcmp(tNode->item.name, temp))
            {
                NodePrint(tNode->item);
                if (!status)
                    status = true;
            }
            tNode = tNode->next;
        }
        break;
    case '3':
        printf("Enter teacher's lesson(< 15 characters): ");
        scanf_s("%s", temp, 15);
        while (tNode)
        {
            if (!strcmp(tNode->item.lesson, temp))
            {
                NodePrint(tNode->item);
                if (!status)
                    status = true;
            }
            tNode = tNode->next;
        }
        break;
    case '4':
        printf("Enter teacher's name(< 15 characters): ");
        scanf_s("%s", temp, 15);
        printf("Enter teacher's lesson(< 15 characters): ");
        scanf_s("%s", temp2, 15);
        while (tNode)
        {
            if (!strcmp(tNode->item.name, temp) && !strcmp(tNode->item.lesson, temp2))
            {
                NodePrint(tNode->item);
                if (!status)
                    status = true;
            }
            tNode = tNode->next;
        }
        break;
    case '5':
        break;
    default:
        puts("Error input!");
        delay();
    }
    return status;
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

// 初始添加信息
void addSomeInfo(List * plist)
{
    AddItem((Item){"赵红军", "软件基础"}, plist);
    AddItem((Item){"李朝海", "电路实验"}, plist);
    AddItem((Item){"吕恕", "概率论与数理统计"}, plist);
    AddItem((Item){"付炜", "电路实验"}, plist);
    AddItem((Item){"刘普生", "大学物理"}, plist);
    AddItem((Item){"张治国", "复变函数"}, plist);
    AddItem((Item){"李朝霞", "大学物理实验"}, plist);
    AddItem((Item){"张瑛", "信号与系统"}, plist);
    AddItem((Item){"王守绪", "无机化学"}, plist);
    AddItem((Item){"陈苑明", "分析化学"}, plist);
    AddItem((Item){"胡文成", "物理化学"}, plist);
    AddItem((Item){"唐泳", "程序设计基础"}, plist);
    AddItem((Item){"赵睿", "仪器分析"}, plist);
    AddItem((Item){"陈奋", "高级语言程序设计"}, plist);
    AddItem((Item){"陈端兵", "程序设计基础"}, plist);
    AddItem((Item){"赵红军", "信号与系统"}, plist);
    AddItem((Item){"吕恕", "微积分"}, plist);
    AddItem((Item){"李朝海", "电子工程设计之电子电路设计基础"}, plist);
    AddItem((Item){"李朝海", "电路实验基础"}, plist);
    AddItem((Item){"周国云", "综合课程实验"}, plist);
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
