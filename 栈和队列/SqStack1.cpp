/**
 * @file SqStack1.cpp
 * @author chena
 * @brief  使用指针实现栈，类似数组
 * @version 0.1
 * @date 2022-04-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

typedef int SElemType;

#define STACK_INIT_SIZE 100 //存储空间初始化分配量
#define STACKINCREMENT  10  // 存储空间分配增量

// 结构体定义
typedef struct SqStack
{
    /* data */
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;

// 栈初始化， 确定基地址和大小
status InitStack(SqStack &S)
{
    S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if(!S.base)  exit(OVERFLOW);

    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
};

// 入栈
status Push(SqStack &S, SElemType e)
{
    // 判断栈是否满
    if(S.top - S.base >= S.stacksize)
    {
        S.base = (SElemType *)realloc(S.base, (STACKINCREMENT + STACK_INIT_SIZE) * sizeof(SElemType));

        if(!S.base) exit(OVERFLOW);

        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    
    *S.top++ = e;
    return OK;
};

// 出栈
status Pop(SqStack &S, SElemType &e)
{
    // 判断栈是否为空
    if(S.top == S.base) return ERROR;

    e = *(--S.top);
    // printf("%d", e);
    return OK;
};

// 获取最顶部元素（不出栈）
status GetTop(SqStack S, SElemType &e)
{
    if(S.top == S.base) return ERROR;
    e = *(S.top-1);
    printf("%d\n", e);
    return OK;    
};

// 栈是否为空
status StackEmpty(SqStack S)
{
    if(S.top == S.base) return TRUE;
    else return FALSE;
};

int main()
{
    SqStack S;
    SElemType e;
    int N;

    InitStack(S);

    scanf("%d", &N);
    while(N)
    {
        Push(S, N % 8);
        N =  N / 8;
    }

    while(!StackEmpty(S))
        Pop(S, e);
}
