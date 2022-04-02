#include <stdio.h>
#include <stdlib.h>
#include "common.h"

typedef int ElemType;

typedef struct QNode
{
    /* data */
    ElemType data;
    QNode * next;
}QNode;

typedef struct LiQuene
{
    QNode* front;
    QNode* rear;
}LiQuene;

status initQueue(LiQuene *&lqu)
{
    lqu = (LiQuene *)malloc(sizeof(LiQuene));
    if(!lqu) exit(OVERFLOW);

    lqu->front = lqu->rear = NULL;
    return OK;
}

status isQueueEmpty(LiQuene *lqu)
{
    if(lqu->front == NULL || lqu->rear == NULL)
        return TRUE;
    else    return FALSE;
}

status enQueue(LiQuene *lqu, ElemType x)
{
    QNode * q = (QNode *)malloc(sizeof(QNode));
    q->data = x;
    q->next = NULL;

    if(lqu->rear == NULL)
        lqu->front = lqu->rear = q;
    else
    {
        lqu->rear->next = q;
        lqu->rear = q;
    }

    return OK;
}

status deQueue(LiQuene *lqu, ElemType &x)
{
    if(isQueueEmpty(lqu)) return ERROR;

    QNode *q = lqu->front;

    if(lqu->front == lqu->rear)
        lqu->front = lqu->rear = NULL;
    else
        lqu->front = q->next;

    x = q->data;
    free(q);
    return OK;
}

int main()
{
    LiQuene * lqu;

    initQueue(lqu);

    for(int i = 0; i < 10; i++)
        enQueue(lqu, i);
    
    ElemType num;
    for(int i = 0; i < 10; i++)
    {
        deQueue(lqu, num);
        printf("%4d", num);
    }

    return 0;
}