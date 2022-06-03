/**
 * @file Binarytree4.cpp
 * @author Chena
 * @brief 树的父亲孩子表示法
 * @version 0.1
 * @date 2022-06-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/***
 * 用数组存储每一个节点，再用first指针指向首孩子节点，再用链表链接
*/
#include <stdio.h>

#define MAXSIZE 100

// 分支
typedef struct Branch
{
    int cIdx;
    struct Branch * next;
}Branch;

// 列表
typedef struct 
{
    /* data */
    int data;
    Branch * first;
}TNode;

// 深度遍历
void perOrder(TNode *p, TNode tree[])
{
    if(p != NULL)
    {
        printf("%d\n", p->data);

        Branch * q;
        q = p->first;
        while(q != NULL)
        {
            perOrder(&tree[q->cIdx], tree);
            q = q->next;
        }
    }
}

// 广度遍历
void level(TNode *tn, TNode tree[])
{
    int front, rear;
    TNode *queue[MAXSIZE];
    front = rear = 0;
    TNode *p;
    if(tn != NULL)
    {
        rear = (rear + 1) % MAXSIZE;
        queue[rear] = tn;
        while(front != rear)
        {
            front = (front + 1) % MAXSIZE;
            p = queue[front];

            printf("%d\n", p->data);
            Branch *q = p->first;

            while(q != NULL)
            {
                rear = (rear + 1) % MAXSIZE;
                queue[rear] = &tree[q->cIdx];
                q = q->next;
            }
        }
    }
}
