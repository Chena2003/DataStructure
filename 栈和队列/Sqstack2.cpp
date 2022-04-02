/**
 * @file Sqstack2.cpp
 * @author chena
 * @brief  使用数组实现栈
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

#define MAXSIZE 100 //最大的空间存储量

// 结构体定义
typedef struct 
{
    ElemType data[MAXSIZE];
    int top;
}Sqstack;

// 初始化，栈顶为-1
status InitStack(Sqstack &S)
{
    S.top = -1;
    return OK;
};

// 入栈
status Push(Sqstack &S, ElemType e)
{
    if(S.top == MAXSIZE)    return ERROR;

    S.data[++S.top] = e;
    return OK;
};

// 出栈
ElemType Pop(Sqstack &S)
{
    if(S.top == -1) return ERROR;

    return S.data[S.top--];
};

int main()
{
    Sqstack S;

    InitStack(S);

    for(int i = 0; i < 10; i++)
        Push(S, i);
    
    for(int i = 0; i < 10; i++)
        printf("%4d", Pop(S));
}