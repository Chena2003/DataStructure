/**
 * @file Queue.cpp
 * @author chena
 * @brief 使用数组实现队列
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

#define MAXSIZE 100

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
    if(qu.rear == MAXSIZE)  return ERROR;

    qu.data[qu.rear++] = x;
    return OK;
};

status deQueue(SqQuene &qu, int &x)
{
    if(qu.front == qu.rear) return ERROR;

    x = qu.data[qu.front++];
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


