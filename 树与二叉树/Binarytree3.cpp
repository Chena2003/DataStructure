/**
 * @file Binarytree3.cpp
 * @author Chena
 * @brief 中序线索二叉树
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>

typedef struct TBTNode
{
    char data;
    int ltag, rtag;
    struct TBTNode * lchild;
    struct TBTNode * rchild;
}TBTNode;

// 创建中序线索二叉树方法
void InThread(TBTNode *p, TBTNode *&pre)
{
    if(p != NULL)
    {
        InThread(p->lchild, pre);
        if(p->lchild == NULL)
        {
            p->lchild = pre;
            p->ltag = 1;
        }
        if(pre != NULL && pre->rchild == NULL)
        {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        InThread(p->rchild, pre);
    }
}

// 创建中序二叉树
void CreateInThread(TBTNode *root)
{
    TBTNode *pre = NULL;

    if(root != NULL)
    {
        InThread(root, pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

// p的后续节点
TBTNode *Next(TBTNode *p)
{
    TBTNode *q;
    if(p->rtag == 0)
    {
        q = p->rchild;
        while(q->ltag == 0)
            q = q->lchild;
        return q;
    }
    else
        return p->rchild;
}

// p的前续节点
TBTNode *Perior(TBTNode *p)
{
    TBTNode *q;
    if(p->ltag == 0)
    {
        q = p->lchild;
        while(q->rtag == 0)
            q = q->rchild;
        return q;
    }
    else
        return p->lchild;
}

// 线索二叉树遍历
void InOrder(TBTNode *root)
{
    TBTNode *p = root;
    while(p->ltag == 0)
        p = p->lchild;
    
    for(; p != NULL; p = Next(p))
        printf("%c", p->data);
}


