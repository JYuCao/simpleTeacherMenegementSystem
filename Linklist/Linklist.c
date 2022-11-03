#include "Linklist.h"

#include <stdlib.h>

/* 函数定义 */
//初始化链表头指针
void InitializeList(List *plist)
{
    plist->head = NULL;
    plist->end = NULL;
    plist->size = 0;
}

//检查链表是否为空
bool ListIsEmpty(const List *plist)
{
    if (plist->size == 0)
        return true;
    else
        return false;
}

//检查链表是否已满
bool ListIsFull(const List *plist)
{
    if (plist->size >= MAXSIZE)
        return true;
    else
        return false;
}

//确定链表项数
unsigned ListItemCount(const List *plist)
{
    return plist->size;
}

//在链表末尾增添项
bool AddItem(Item item, List *plist)
{
    Node *pnew;

    if (ListIsFull(plist))
        return false;
    pnew = (Node *)malloc(sizeof(Node));
    if (!pnew)
        return false;

    CopyToNode(item, pnew);
    pnew->next = NULL;
    pnew->prev = NULL;
    if (!plist->end)
        plist->head = pnew;
    else
    {
        pnew->prev = plist->end;
        plist->end->next = pnew;
    }
    plist->end = pnew;
    ++plist->size;
    return true;
}

//在链表中插入项
bool InsertItem(Item item, List *plist, int i)
{
    Node *pnew;
    Node *ptemp;
    int j = 0;

    if (ListIsFull(plist))
        return false;
    pnew = (Node *)malloc(sizeof(Node));
    if (!pnew)
        return false;

    CopyToNode(item, pnew);

    ptemp = plist->head;
    if (!ptemp)
    {
        if (i == 1)
        {
            plist->head = pnew;
            plist->end = pnew;
            pnew->next = NULL;
            pnew->prev = NULL;
        }
        else
            return false;
    }
    else
    {
        while (ptemp->next && j < i - 1)
        {
            ptemp = ptemp->next;
            ++j;
        }
        if (j != i - 1)
            return false;

        if (ptemp->prev) {
            pnew->prev = ptemp->prev;
            pnew->prev->next = pnew;
            pnew->next = ptemp;
        } else {
            pnew->prev = NULL;
            pnew->next = ptemp;
            plist->head = pnew;  
        }
        ptemp->prev = pnew;
    }
    ++plist->size;
    return true;
}

//在链表中删除项
bool DeleteItem(List *plist, int i)
{
    Node *ptemp;
    int j = 0;

    if (ListIsEmpty(plist))
        return false;

    ptemp = plist->head;
    while (ptemp->next && j < i - 1)
    {
        ptemp = ptemp->next;
        ++j;
    }
    if (j != i - 1)
        return false;
    ptemp = ptemp->next;
    if (ptemp->prev)
        ptemp->prev->next = ptemp->next;
    else
        plist->head = ptemp->next;
    if (ptemp->next)
        ptemp->next->prev = ptemp->prev;
    else
        plist->end = ptemp->prev;

    --plist->size;
    free(ptemp);
    return true;
}

//指向的函数作用于链表每一项一次（正序）
void Traverse(const List *plist, void (*pfun)(Item item))
{
    Node *pt = plist->head;

    while (pt)
    {
        (*pfun)(pt->item);
        pt = pt->next;
    }
}

//释放链表内存，设置链表为空
void EmptyTheList(List *plist)
{
    Node *psave;

    while (plist->head)
    {
        psave = plist->head->next;
        free(plist->head);
        plist->head = psave;
    }
}

//拷贝新内容到新节点
void CopyToNode(Item item, Node *pnode)
{
    pnode->item = item;
}

//打印节点内容
void NodePrint(Item item)
{
    printf("ID:%s\tName:%s\tGrade:%.1f\n",
           item.id, item.name, item.grade);
}