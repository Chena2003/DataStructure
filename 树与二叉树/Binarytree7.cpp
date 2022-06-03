/**
 * @file Binarytree7.cpp
 * @author Chena
 * @brief 由先序和后序序列确定二叉树
 * @version 0.1
 * @date 2022-06-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>


typedef struct BTNode
{
    char data;
    BTNode *lchild;
    BTNode *rchild;
}BTNode;

BTNode *CreateBT(char pre[], char in[], int L1, int R1, int L2, int R2)
{
    if(L1 > R1)
        return NULL;

    BTNode *s = (BTNode *)malloc(sizeof(BTNode));
    s->lchild = s->rchild = NULL;
    s->data = pre[L1];

    int i;
    for(i = L2; i <= R2; i++)
        if(in[i] = pre[L1])
            break;
    
    s->lchild = CreateBT(pre, in, L1+1, L1+i-L2, L2, i-1);
    s->rchild = CreateBT(pre, in, L1+i-L2+1, R1, i+1, R2);
    return s;
}