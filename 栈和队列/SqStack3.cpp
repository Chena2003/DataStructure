#include <stdio.h>
#include <stdlib.h>
#include "common.h"

typedef int ElemType;


typedef struct SqStack
{
    /* data */
    ElemType data;
    struct SqStack * next;
}SqStack;

status InitStack(SqStack *&S)
{
    S = (SqStack *)malloc(sizeof(SqStack));
    if(!S) exit(OVERFLOW);
    S->next = NULL;
    return OK;
};

status isEmpty(SqStack *S)
{
    if(S->next == NULL) return TRUE;
    else                return FALSE;
};

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
