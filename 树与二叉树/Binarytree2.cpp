/**
 * @file Binarytree2.cpp
 * @author Chena
 * @brief 二叉树遍历算法(非递归)
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>

#define MAXSIZE 100

typedef struct BTNode
{
    char data;
    struct BTNode * lchild;
    struct BTNode * rchild;
}BTNode;

// 前序遍历
void preorder(BTNode *p)
{
    if(p != NULL)
    {
        BTNode * Stack[MAXSIZE];
        int top = -1;
        BTNode *q;
        Stack[++top] = p;

        while(top != -1)
        {
            q = Stack[top--];
            printf("%c", q->data);

            if(q->rchild != NULL)
            {
                Stack[++top] = q->rchild;
            }
            if(q->lchild != NULL)
            {
                Stack[++top] = q->lchild;
            }
        }
    }
}

// 中序遍历
void inorder(BTNode *p)
{
    if(p != NULL)
    {
        BTNode *Stack[MAXSIZE];
        int top = -1;
        BTNode *q = p;

        while(top != -1 || p != NULL)
        {
            while(p != NULL)
            {
                Stack[++top] = q;
                q = q->lchild;
            }

            if(top != -1)
            {
                q = Stack[top--];
                printf("%c", q->data);
                p = p->rchild;
            }
        }
    }
}

// 后序遍历
void postorder(BTNode *p)
{
    if(p != NULL)
    {
        BTNode * Stack1[MAXSIZE];
        BTNode * Stack2[MAXSIZE];
        int top1, top2;
        top1 = top2 = -1;
        Stack1[++top1] = p;
        BTNode *q;

        while(top1 != -1)
        {
            q = Stack1[top1--];
            Stack2[++top2] = q;

            if(q->lchild != NULL)
            {
                Stack1[++top1] = q->lchild;
            }
            if(q->rchild != NULL)
            {
                Stack1[++top1] = q->rchild;
            }
        }

        while (top2 != -1)
        {
            printf("%c", Stack2[top2--]->data);
        }
    }
}