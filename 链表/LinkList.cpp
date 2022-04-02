/**
 * @file LinkList.cpp
 * @author chena
 * @brief 链表的基本操作
 * @version 0.1
 * @date 2022-04-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

typedef int ElemType;

// 结构体定义
typedef struct LNode 
{
    ElemType data;
    struct LNode * next;
}LNode, * LinkList;

// 初始化链表
LNode* InitList_L(void)
{
    LNode * L = (LNode *)malloc(sizeof(LNode));
    if(!L) exit(OVERFLOW);

    L->next = NULL;
    return L;
};

// 获取第i个位置的值
status GetElem_L(LinkList L, int i, ElemType &e)
{
    LinkList p = L->next;
    int j = 1;

    while(p && j++ < i)
    {
        p = p ->next;
    }

    if(!p || j > i) return ERROR; // 第i个元素不存在

    e = p->data;
    return OK;
};

// 在链表中第i个元素位置插入元素
status ListInsert_L(LinkList &L, int i, ElemType e)
{
    LinkList p = L->next;
    int j = 1;

    // 寻找第 i-1 个元素
    while(p && j++ < i - 1)
    {
        p = p -> next;
    }
    if(!p || j > i - 1) return ERROR; // 第i-1个元素不存在

    LinkList q = (LinkList)malloc(sizeof(LNode));
    if(!q) exit(OVERFLOW);
    q->next = NULL;
    q->data = e;

    q->next = p->next;
    p->next = q;

    return OK;
};

// 删除链表中第i个元素
status ListDelete_L(LinkList &L, int i, ElemType &e)
{
    LinkList p = L->next, q;
    int j = 1;

    // 寻找第i-1
    while(p && j < i-1)
    {
        p = p -> next;
    }
    if(!p || j > i - 1) return ERROR; // 第i-1个元素不存在

    q = p -> next;
    e = q -> data;
    p->next = q->next;
    free(q);

    return OK;
};

// 头插法创建链表, 数据为倒序
void CreateList_L(LinkList &L, int n)
{
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    int i = 1;

    while(i++ <= n)
    {
        LinkList p = (LinkList)malloc(sizeof(LNode));
        p->next = NULL;

        scanf("%d", &p->data);
        p->next = L->next;
        L->next = p;
    }

};

// 尾插法创建链表， 数据为正序
void CreateList_R(LinkList &L, int n)
{
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    int i = 1;

    LinkList r = L;
    while(i++ <= n)
    {
        LinkList p = (LinkList)malloc(sizeof(LNode));
        p->next = NULL;

        scanf("%d", &p->data);
        p->next = r->next;
        r->next = p;
        r = p;
    }

};

int main()
{
    int n, i = 1;
    LinkList head;

    scanf("%d", &n);
    CreateList_R(head, n);

    LinkList q = head;
    while(q->next != NULL)
    {
        q = q->next;
        printf("%3d", q->data);
    }

    return 0;
}
