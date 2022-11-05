#ifndef _SQLIST_H
#define _SQLSIT_H

#define true 1
#define false 0
#define bool int

#define MAXSIZE 100

typedef struct item {      //项数组中存储内容，按需修改
    char * name;
    char * lesson;
} Item;

/* 一般类型定义 */
typedef struct list {
    Item entries[MAXSIZE];
    int items;
} List;

/* 函数原型 */
//初始化项数组
void InitializeItem(List * list);

//检查项数组是否为空
bool ItemIsEmpty(const List * list);

//检查项数组是否已满
bool ItemIsFull(const List * list);

//确定项数组项数
unsigned ItemItemCount(const List * list);

//在项数组增添项
bool AddItem(Item item, List * list);

//在项数组删除项(n+1项)
bool DeleteItem(List * list, int n);

//指向的函数作用于项数组每一项一次
void Traverse(const List * list, void (*pfun)(Item item));

//清空项数组
void EmptyTheList(List * list);

#endif
