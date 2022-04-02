/**
 * @file SqStack3.cpp
 * @author your name (you@domain.com)
 * @brief 链栈
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
typedef struct SqStack
{
    /* data */
    ElemType data;
    struct SqStack * next;
}SqStack;

// 栈初始化
status InitStack(SqStack *&S)
{
    S = (SqStack *)malloc(sizeof(SqStack));
    if(!S) exit(OVERFLOW);
    S->next = NULL;
    return OK;
};

// 判断栈是否为空
status isEmpty(SqStack *S)
{
    if(S->next == NULL) return TRUE;
    else                return FALSE;
};

// 出栈
status Push(SqStack *&S, ElemType e)
{
    SqStack * p;
    p = (SqStack *)malloc(sizeof(SqStack));
    if(!p)  exit(OVERFLOW);

    p->data = e;
    // 头插法插入元素
    p->next = S->next;
    S->next = p;

    return OK;
};

// 出栈
ElemType Pop(SqStack *&S)
{
    if(isEmpty(S)) return ERROR;

    SqStack *p;
    p = (SqStack *)malloc(sizeof(SqStack));

    p = S->next;
    ElemType e = p->data;
    S->next = p->next;
    free(p);
    return e;
};

int main()
{
    SqStack * S;

    InitStack(S);

    for(int i = 0; i < 10; i++)
        Push(S, i);

    for(int i = 0; i < 10; i++)
        printf("%4d", Pop(S));

    return 0;
}
