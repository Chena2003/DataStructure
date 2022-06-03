/**
 * @file Binarytree9.cpp
 * @author Chena
 * @brief 由层次和中序序列确定二叉树
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

int search(char arr[], char key, int L, int R)
{
    int i;
    for(i = L; i <= R; i++)
        if(arr[i] == key)
            return i;
    
    return -1;
}

void getSubLevel(char subLevel[], char level[], char in[], int n, int L, int R)
{
    int k = 0;
    for(int i = 0; i < n; i++)
        if(search(in, level[i], L, R) != -1)
            subLevel[k++] = level[i];
}

BTNode *CreateBT(char level[], char in[], int n, int L, int R)
{
    if(L > R)
        return NULL;

    BTNode *s = (BTNode *)malloc(sizeof(BTNode));
    s->lchild = s->rchild = NULL;
    s->data = level[0];

    int i = search(in, level[0], L, R);
    int LN = i-L; char llevel[LN];
    int RN = R-L; char rlevel[RN];

    getSubLevel(llevel, level, in, n, L, i-1);
    getSubLevel(rlevel, level, in, n, i+1, R);

    CreateBT(llevel, in, LN, L, i-1);
    CreateBT(rlevel, in, RN, i+1, R);

    return s;
}