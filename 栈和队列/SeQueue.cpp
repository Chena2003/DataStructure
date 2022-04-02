#include <stdio.h>
#include <stdlib.h>
#include "common.h"

typedef int ElemType;

#define MAXSIZE 11

typedef struct 
{
    ElemType data[MAXSIZE];
    int front;
    int rear;
}SqQuene;

void initQueue(SqQuene &qu)
{
    qu.front = qu.rear = 0;
};

status enQueue(SqQuene &qu, int x)
{
    if((qu.rear+1)%MAXSIZE == qu.front)  return ERROR;
    
    qu.data[qu.rear] = x;
    qu.rear = (qu.rear+1) % MAXSIZE;

    return OK;
};

status deQueue(SqQuene &qu, int &x)
{
    if(qu.front == qu.rear) return ERROR;

    x = qu.data[qu.front];
    qu.front = (qu.front+1) % MAXSIZE;
    
    return OK;
};

int main()
{
    SqQuene Qe;

    initQueue(Qe);

    for(int i = 0; i < 10; i++)
        enQueue(Qe, i);

    ElemType num;
    for(int i = 0; i < 10; i++)
    {
        deQueue(Qe, num);
        printf("%4d", num);
    }

    return 0;
}
