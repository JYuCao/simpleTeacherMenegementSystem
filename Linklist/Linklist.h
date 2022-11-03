#ifndef _LINKLIST_H
#define _LINKLIST_H

#define true 1
#define false 0
#define bool int

// 链表大小
#define MAXSIZE 100


typedef struct item
{ //链表中存储内容，按需修改
    char id[3];
    char name[10];
    float grade;
} Item;

/* 一般类型定义 */
typedef struct node
{
    Item item;
    struct node *next;
    struct node *prev;
} Node;

typedef struct list
{
    Node *head;
    Node *end;
    unsigned int size;
} List;


/* 函数原型 */

//初始化链表指针
void InitializeList(List *plist);

//检查链表是否为空
bool ListIsEmpty(const List *plist);

//检查链表是否已满
bool ListIsFull(const List *plist);

//确定链表项数
unsigned ListItemCount(const List *plist);

//在链表末尾增添项
bool AddItem(Item item, List *plist);

//在链表中插入项
bool InsertItem(Item item, List *plist, int i);

//在链表中删除项
bool DeleteItem(List *plist, int i);

//指向的函数作用于链表每一项一次（正序）
void Traverse(const List *plist, void (*pfun)(Item item));

//释放链表内存，设置链表为空
void EmptyTheList(List *plist);

//拷贝新内容到新节点
void CopyToNode(Item item, Node *pnode);

//打印节点内容
void NodePrint(Item item);

#endif