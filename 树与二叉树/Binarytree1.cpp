/**
 * @file Binarytree.cpp
 * @author Chena
 * @brief 树的左右孩子表示方法
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>

#define MAXSIZE 100

// 左右孩子表示法
typedef struct BTNode
{
    char data;  //数据
    struct BTNode * lchild; // 左孩子
    struct BTNode * rchild; // 右孩子
}BTNode;

// 先序遍历
void preorder(BTNode *p)
{
    if(p != NULL)
    {
        printf("%c", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

// 中序遍历
void inorder(BTNode *p)
{
    if(p != NULL)
    {
        inorder(p->lchild);
        printf("%c", p->data);
        inorder(p->rchild);
    }
}

// 后序遍历
void postorder(BTNode *p)
{
    if(p != NULL)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%c", p->data);
    }
}

// 求二叉树深度
int getDepth(BTNode *p)
{
    int LD, RD;
    if(p == NULL)
        return 0;
    else
    {
        LD = getDepth(p->lchild);
        RD = getDepth(p->rchild);
        return (LD>RD?LD:RD) + 1;
    }
}

// 按值查找
void search(BTNode *p, BTNode *&q, char key)
{
    if(p != NULL)
    {
        if(p->data == key)
            q = p;
        else
        {
            search(p->lchild, q, key);
            if(q == NULL)
                search(p->rchild, q, key);
        }
    }
}

// 层次遍历
// 将结果放在循环队列中
void level(BTNode *p)
{
    int front, rear;
    BTNode *queue[MAXSIZE];
    front = rear = 1;
    BTNode *q;
    
    if(p != NULL)
    {
        rear = (rear + 1) % MAXSIZE;
        queue[rear] = p;

        while(front != rear)
        {
            front = (front + 1) % MAXSIZE;
            q = queue[front];

            printf("%c", q->data);
            if(q->lchild != NULL)
            {
                rear = (rear + 1) % MAXSIZE;
                queue[rear] = q->lchild;
            }
            if(q->rchild != NULL)
            {
                rear = (rear + 1) % MAXSIZE;
                queue[rear] = q->rchild;
            }
        }
    }
}


