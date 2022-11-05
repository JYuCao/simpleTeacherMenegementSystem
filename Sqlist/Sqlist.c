#include "Sqlist.h"

//局部函数，拷贝新内容到新节点
static void CopyToList(Item item, Item entries[]);

/* 接口函数定义 */
//初始化项数组
void InitializeItem(List * list)
{
    list->items = 0;
}

//检查项数组是否为空
bool ItemIsEmpty(const List * list)
{
    if (list->items == 0)
        return true;
    else
        return false;
}

//检查项数组是否已满
bool ItemIsFull(const List * list)
{
    if (list->items >= MAXSIZE)
        return true;
    else
        return false;
}

//确定项数组项数
unsigned ItemItemCount(const List * list)
{
    return list->items;
}

//在项数组增添项
bool AddItem(Item item, List * list)
{
    if (ItemIsFull(list))
        return false;

    list->entries[list->items++] = item;
    return true;
}

//在项数组删除项(第n+1个)
bool DeleteItem(List * list, int n)
{
    if (ItemIsEmpty(list))
    {
        return false;
    }
    free(list->entries[n].lesson);
    free(list->entries[n].name);
    list->entries[n] = list->entries[--list->items];

    return true;
}

//指定的函数作用于项数组每项一次
void Traverse(const List * list, void (*pfun)(Item item))
{
    for (int i = 0; i < list->items; ++i) {
        (*pfun)(list->entries[i]);
    }
}