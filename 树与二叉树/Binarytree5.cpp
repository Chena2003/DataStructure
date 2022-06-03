/**
 * @file Binarytree5.cpp
 * @author Chena
 * @brief 前序线索二叉树
 * @version 0.1
 * @date 2022-06-03
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


// 创建前序线索二叉树方法
void PreThread(TBTNode *p, TBTNode *&pre)
{
    if(p != NULL)
    {
        if(p->lchild = NULL)
        {
            p->lchild = pre;
            p->ltag = 1;
        }

        if(pre->rchild == NULL && pre != NULL)
        {
            pre->rchild = p;
            pre->rtag = 1;
        }

        pre = p;
        if(p->ltag == 0)
            PreThread(p->lchild, pre);
        if(p->rtag == 0)
            PreThread(p->rchild, pre);
    }
}

// 创建前序线索二叉树
void CreatePreThread(TBTNode *root)
{
    TBTNode *pre = NULL;

    if(root != NULL)
    {
        PreThread(root, pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

// 后序节点
TBTNode *Next(TBTNode *p)
{
    if(p->rtag == 0)
        return p->lchild;
    else
        return p->rchild;
}

// 前序遍历
void PreOrder(TBTNode *root)
{
    if(root != NULL)
    {
        TBTNode *p = root;

        while(p != NULL)
        {
            printf("%d\n", p->data);
            p = Next(p);
        }
    }
}