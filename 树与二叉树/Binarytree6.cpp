/**
 * @file Binarytree6.cpp
 * @author Chena
 * @brief 后续线索二叉树
 * @version 0.1
 * @date 2022-06-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>


typedef struct TBTNode
{
    int data;
    int ltag, rtag;
    TBTNode *lchild;
    TBTNode *rchild;
}TBTNode;

// 创建后序线索二叉树的方法
void PostThread(TBTNode *p, TBTNode *pre)
{
    if(p != NULL)
    {
        PostThread(p->lchild, pre);
        PostThread(p->rchild, pre);

        if(p->lchild == NULL)
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
    }
}

// 创建后序线索二叉树
void CreatePostThread(TBTNode *root)
{
    TBTNode *pre;

    if(root != NULL)
    {
        PostThread(root, pre);
    }
}