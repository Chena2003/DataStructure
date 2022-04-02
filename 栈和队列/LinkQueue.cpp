/**
 * @file LinkQueue.cpp
 * @author chena
 * @brief 使用链表实现队列
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

// 队列节点结构体定义
typedef struct QNode
{
    /* data */
    ElemType data;
    QNode * next;
}QNode;

// 队列结构体定义
typedef struct LiQuene
{
    QNode* front;   //头节点
    QNode* rear;    //尾节点
}LiQuene;

// 队列初始化，头节点和尾节点赋值为NULL
status initQueue(LiQuene *&lqu)
{
    lqu = (LiQuene *)malloc(sizeof(LiQuene));
    if(!lqu) exit(OVERFLOW);

    lqu->front = lqu->rear = NULL;
    return OK;
}

// 队列是否为空
status isQueueEmpty(LiQuene *lqu)
{
    if(lqu->front == NULL || lqu->rear == NULL)
        return TRUE;
    else    return FALSE;
}

// 入队列
status enQueue(LiQuene *lqu, ElemType x)
{
    QNode * q = (QNode *)malloc(sizeof(QNode));
    q->data = x;
    q->next = NULL;

    // 如队列为空，特殊处理
    if(lqu->rear == NULL)
        lqu->front = lqu->rear = q;
    else
    {
        lqu->rear->next = q;
        lqu->rear = q;
    }

    return OK;
}

// 出队列
status deQueue(LiQuene *lqu, ElemType &x)
{
    if(isQueueEmpty(lqu)) return ERROR;

    QNode *q = lqu->front;

    // 如队列中只有一个元素，则特殊处理
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