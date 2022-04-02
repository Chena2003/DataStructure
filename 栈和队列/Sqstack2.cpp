#include <stdio.h>
#include <stdlib.h>
#include "common.h"

typedef int ElemType;

#define MAXSIZE 100 //最大的空间存储量

typedef struct 
{
    ElemType data[MAXSIZE];
    int top;
}Sqstack;

status InitStack(Sqstack &S)
{
    S.top = -1;
    return OK;
};

status Push(Sqstack &S, ElemType e)
{
    if(S.top == MAXSIZE)    return ERROR;

    S.data[++S.top] = e;
    return OK;
};

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